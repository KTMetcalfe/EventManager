//
//  ContentView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/2/22.
//

import SwiftUI
import Combine

struct ContentView: View {
    @State private var login: String = ""
    @State private var location: String = ""
    
    var body: some View {
        
        VStack {
            Text("Event Manager")
                .font(.largeTitle)
            Form {
                Section {
                    TextField("Login Code", text: $login)
                        .font(.title3)
                        .padding()
                        .multilineTextAlignment(.center)
                        .keyboardType(.decimalPad)
                        .onReceive(Just(login)) { newValue in
                                        let filtered = newValue.filter { "0123456789".contains($0) }
                                        if filtered != newValue {
                                            self.login = filtered
                                        }
                        }
                    TextField("Location Code", text: $location)
                        .font(.title3)
                        .padding()
                        .multilineTextAlignment(.center)
                        .keyboardType(.decimalPad)
                        .onReceive(Just(location)) { newValue in
                                        let filtered = newValue.filter { "0123456789".contains($0) }
                                        if filtered != newValue {
                                            self.location = filtered
                                        }
                        }
                }
                HStack() {
                    Spacer()
                    Button("Login") {
                        
                    }
                    .font(.title3)
                    Spacer()
                }
            }
            .frame(maxHeight: 300)
            .cornerRadius(15)
            .padding()
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
