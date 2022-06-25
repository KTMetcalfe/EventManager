//
//  CheckoutView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/21/22.
//

import SwiftUI
import SquareReaderSDK

struct CheckoutView: View {
    @EnvironmentObject var checkoutObserver: CheckoutObserver
    
    @State private var totalCost: Int = 0
    
    var body: some View {
        CheckoutViewRepresentable()
    }
}

// CheckoutView Representable
struct CheckoutViewRepresentable: UIViewControllerRepresentable {
    @EnvironmentObject var checkoutObserver: CheckoutObserver
    
    func makeUIViewController(context: Context) -> CheckoutViewController {
        let checkout = CheckoutViewController()
        checkout.checkoutObserver = checkoutObserver
        return CheckoutViewController()
    }
    
    func updateUIViewController(_ uiViewController: CheckoutViewController, context: Context) {
        if checkoutObserver.checkoutPrice != 0 && uiViewController.isViewLoaded{
            uiViewController.startCheckout(amount: checkoutObserver.checkoutPrice)
        }
    }
}

// Square Checkout Function
class CheckoutViewController: SquareViewController {
    var checkoutObserver: CheckoutObserver = CheckoutObserver()
    
    func startCheckout(amount: Int) {
        // Create a money amount in the currency of the authorized Square account
        let amountMoney = SQRDMoney(amount: amount)

        // Create parameters to customize the behavior of the checkout flow.
        let params = SQRDCheckoutParameters(amountMoney: amountMoney)
        params.additionalPaymentTypes = [.cash, .manualCardEntry]

        // Create a checkout controller and call present to start checkout flow.
        let checkoutController = SQRDCheckoutController(
            parameters: params,
            delegate: self
        )
        checkoutController.present(from: self)
    }
}

// Square Checkout Extension
extension CheckoutViewController: SQRDCheckoutControllerDelegate {
    public func checkoutControllerDidCancel(
        _: SQRDCheckoutController
    ) {
        print("Checkout cancelled.")
    }

    public func checkoutController(
        _: SQRDCheckoutController, didFailWith error: Error
    ) {
        // TODO: Handle checkout errors
        // Checkout controller errors are always of type SQRDCheckoutControllerError
        let checkoutControllerError = error as! SQRDCheckoutControllerError

        switch checkoutControllerError.code {
        case .sdkNotAuthorized:
            // Checkout failed because the SDK is not authorized
            // with a Square merchant account.
            print("Reader SDK is not authorized.")
        case .usageError:
            // Checkout failed due to a usage error. Inspect the userInfo
            // dictionary for additional information.
            if let debugMessage = checkoutControllerError.userInfo[SQRDErrorDebugMessageKey],
                let debugCode = checkoutControllerError.userInfo[SQRDErrorDebugCodeKey] {
                print(debugCode, debugMessage)
            }
        @unknown default:
            fatalError()
        }
    }

    public func checkoutController(
        _: SQRDCheckoutController,
        didFinishCheckoutWith result: SQRDCheckoutResult
    ) {
        // TODO: Handle checkout success
        // result contains details about the completed checkout
        print("Checkout completed: \(result.description).")
    }
}

struct CheckoutView_Previews: PreviewProvider {
    static var previews: some View {
        CheckoutView().environmentObject(CheckoutFunction())
    }
}
