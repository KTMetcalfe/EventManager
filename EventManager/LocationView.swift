//
//  MainView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/2/22.
//

import SwiftUI

struct LocationView: View {
    @State @AppStorage("username") private var username = ""
    @State @AppStorage("password") private var password = ""
    @State @AppStorage("location") private var location = ""
    @State @AppStorage("location_name") private var location_name = ""
    @AppStorage("isLoggedIn") private var isLoggedIn = false
    
    @State private var outJson: [Item] = [Item].init()
    
    @State private var spinDeg = 0.0
    
    @State var isPreview: Bool = false
    
    func getItems() {
        #if false
            outJson = Helper.load(name: "BratTent")
        #else
            let url = URL(string: "https://em.kianm.net/index.php/item/list")!

            var request = URLRequest(url: url)
            request.httpMethod = "POST"
            request.setValue("application/json", forHTTPHeaderField: "Content-Type")
            request.setValue("application/json", forHTTPHeaderField: "Accept")
            request.setValue("Basic " + (username + ":" + password).toBase64(), forHTTPHeaderField: "Authorization")
            request.httpBody = String(format: "{\"location\": \"%@\"}", location).data(using: .utf8)
            
            let task = URLSession.shared.dataTask(with: request) {
                data, response, error in
                guard
                    error == nil,
                    let data = data,
                    let string = String(data: data, encoding: .utf8)
                else {
                    print(error ?? "Unknown error")
                    return
                }

                print(string)
                outJson = Helper.decode(outData: data)
                print(String(outJson.count))
            }
            task.resume()
        #endif
    }
    
    var body: some View {
        VStack {
            HStack {
                VStack {
                    Button("Sign out") {
                        isLoggedIn = false
                    }
                    Text(location_name)
                }
                Button(action: {
                    getItems()
                    spinDeg += 360.0
                }) {
                    Image(systemName: "arrow.clockwise")
                        .rotationEffect(.degrees(spinDeg))
                }
                .animation(.easeInOut, value: spinDeg)
            }
            if #available(iOS 16.0, *) {
                GridView(outJson: !isPreview ? $outJson : .constant(Helper.load(name: "BratTent"))).environmentObject(CheckoutFunction())
            } else {
                // Fallback on earlier versions
                List(outJson) { item in
                    Button(item.name + " " + String(item.price)) {}
                }
            }
        }.onAppear { getItems() }
    }
}

struct LocationView_Previews: PreviewProvider {
    static var previews: some View {
        LocationView(isPreview: true)
    }
}
