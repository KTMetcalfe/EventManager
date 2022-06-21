//
//  ContentView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/2/22.
//

import SwiftUI

struct ContentView: View {
    @AppStorage("isLoggedIn") private var isLoggedIn = false
    
    var body: some View {
        if (!isLoggedIn) {
            LoginView()
        } else {
            if #available(iOS 16.0, *) {
                NavigationStack{
                    LocationView()
                }
            } else {
                // Fallback on earlier versions
                NavigationView{
                    LocationView()
                }
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
