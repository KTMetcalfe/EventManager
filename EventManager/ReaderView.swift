//
//  ReaderView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/24/22.
//

import SwiftUI
import SquareReaderSDK

struct ReaderView: View {
    @EnvironmentObject var readerObserver: ReaderObserver
    var body: some View {
        ReaderViewRepresentable()
    }
}

// ReaderView Representable
struct ReaderViewRepresentable: UIViewControllerRepresentable {
    @EnvironmentObject var readerObserver: ReaderObserver
    
    func makeUIViewController(context: Context) -> ReaderViewController {
        return ReaderViewController()
    }
    
    func updateUIViewController(_ uiViewController: ReaderViewController, context: Context) {
        if readerObserver.showReader && uiViewController.isViewLoaded{
            uiViewController.pairCardReaders()
        }
    }
}

class ReaderViewController: SquareViewController {
    var readerObserver: ReaderObserver = ReaderObserver()
}

// Square Reader Extension
extension ReaderViewController: SQRDReaderSettingsControllerDelegate {
    func pairCardReaders() {
        let readerSettingsController = SQRDReaderSettingsController(
            delegate: self
        )
        readerSettingsController.present(from: self)
    }

    // MARK: - SQRDReaderSettingsControllerDelegate

    public func readerSettingsControllerDidPresent(
        _: SQRDReaderSettingsController
    ) {
        print("Reader settings flow presented.")
    }

    public func readerSettingsController(
        _: SQRDReaderSettingsController,
        didFailToPresentWith error: Error
    ) {
        // Handle the error - this example prints the error to the console
        print(error)
    }
}

struct ReaderView_Previews: PreviewProvider {
    static var previews: some View {
        ReaderView()
    }
}
