//
//  ContentView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/2/22.
//

import SwiftUI

struct ContentView: View {
    @AppStorage("isLoggedIn") private var isLoggedIn = false
    @AppStorage("isAuthorized") private var isAuthorized = false
    
    var body: some View {
        if (!isLoggedIn) {
            LoginView()
        } else if (!isAuthorized) {
            AuthorizeView()
        } else {
            if #available(iOS 16.0, *) {
                NavigationStack{
                    LocationView().environmentObject(CheckoutFunction()).environmentObject(CheckoutObserver()).environmentObject(ReaderObserver())
                }
            } else {
                // Fallback on earlier versions
                LocationView().environmentObject(CheckoutFunction()).environmentObject(CheckoutObserver()).environmentObject(ReaderObserver())
            }
        }
    }
}

class CheckoutObserver: ObservableObject {
    @Published public var checkoutPrice: Int = 0
}

class ReaderObserver: ObservableObject {
    @Published public var showReader: Bool = false
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
