//
//  CheckoutView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/21/22.
//

import SwiftUI

struct CheckoutView: View {
    @EnvironmentObject var checkoutModel: CheckoutFunction
    
    @State private var totalCost: Int = 0
    
    func getPrice() {
        var cost = 0
        checkoutModel.checkoutList.forEach { item in
            cost += item.price
        }
        totalCost = cost;
    }
    
    var body: some View {
        Text("Your total: " + Helper.formatPrice(price: totalCost))
            .onAppear { getPrice() }
    }
}

struct CheckoutView_Previews: PreviewProvider {
    static var previews: some View {
        CheckoutView().environmentObject(CheckoutFunction())
    }
}
