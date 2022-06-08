//
//  MainView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/2/22.
//

import SwiftUI

struct MainView: View {
    @State @AppStorage("username") private var username = ""
    @State @AppStorage("password") private var password = ""
    @State @AppStorage("location") private var location = ""
    @State @AppStorage("location_name") private var location_name = ""
    @AppStorage("isLoggedIn") private var isLoggedIn = false
    
    @State private var outJson: [Item] = [Item].init()
    
    struct Item: Codable {
        var id: Int
        var name: String
        var price: Int
        var imageUrl: String
        var multipliers: String
        var locations: String
    }
    
    func decode(outData: Data) {
        outJson = try! JSONDecoder().decode([Item].self, from: outData)
    }
    
    func getItems() {
        print(username + ":" + password)
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
            decode(outData: data)
        }
        task.resume()
    }
    
    var body: some View {
        VStack {
            Button("Sign out") {
                isLoggedIn = false
            }
            VStack {
                Text(location_name)
                List(outJson, id: \.id) { item in
                    Button(item.name + " " + String(item.price)) {
                    }
                }
                .onAppear {
                    getItems()
            }
            }
        }
    }
}

struct MainView_Previews: PreviewProvider {
    static var previews: some View {
        MainView()
    }
}
