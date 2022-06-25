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
    
    @EnvironmentObject var checkoutModel: CheckoutFunction
    @EnvironmentObject var checkoutObserver: CheckoutObserver
    @EnvironmentObject var readerObserver: ReaderObserver
    
    func getItems() {
        #if false
            outJson = JSONHelper.load(name: "BratTent")
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
                outJson = JSONHelper.decode(outData: data)
                print(String(outJson.count))
            }
            task.resume()
        #endif
    }
    
    var body: some View {
        VStack {
            HStack {
                Button(action: {
                    readerObserver.showReader = true
                }) {
                    Image(systemName: "gearshape")
                }
                VStack {
                    Button("Sign out") {
                        checkoutObserver.checkoutPrice = 0
                        readerObserver.showReader = false
                        isLoggedIn = false
                    }
                    Text(location_name)
                }
                Button(action: {
                    checkoutModel.checkoutList = []
                    checkoutObserver.checkoutPrice = 0
                    getItems()
                    spinDeg += 360.0
                }) {
                    Image(systemName: "arrow.clockwise")
                        .rotationEffect(.degrees(spinDeg))
                }
                .animation(.easeInOut, value: spinDeg)
            }
            ReaderView().environmentObject(readerObserver).frame(width: 0, height: 0)
            GridView(outJson: !isPreview ? $outJson : .constant(JSONHelper.load(name: "BratTent"))).environmentObject(checkoutModel).environmentObject(checkoutObserver)
        }.onAppear { getItems() }
    }
}

struct LocationView_Previews: PreviewProvider {
    static var previews: some View {
        LocationView(isPreview: true)
    }
}
