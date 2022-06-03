//
//  MainView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/2/22.
//

import SwiftUI

struct MainView: View {
    @AppStorage("isLoggedIn") private var isLoggedIn = true
    
    @State private var outJson: [Item] = [Item].init()
    
//    func getItems() {
//        let url = URL(string: "https://api.kianm.net/index.php/vehicles/list")!
//
//        let task = URLSession.shared.dataTask(with: url) {
//            data, response, error in
//            guard
//                error == nil,
//                let data = data,
//                let string = String(data: data, encoding: .utf8)
//            else {
//                print(error ?? "Unknown error")
//                return
//            }
//
//            print(string)
//
//            decode(outData: data)
//        }
//        task.resume()
//    }
    
    struct Item: Codable {
        var id: Int
        var name: String
        var price: Int
        var imageUrl: String
        var multipliers: String
    }
    
    func decode(outData: Data) {
        outJson = try! JSONDecoder().decode([Item].self, from: outData)
    }
    
    var body: some View {
        VStack {
            Button("Sign out") {
                isLoggedIn = false
            }
            List(outJson, id: \.id) { item in
                Button(item.name + " " + String(item.price)) {
                }
            }
            .onAppear {
                decode(outData: "[{\"id\": 0,\"name\": \"Brat\",\"price\": 400,\"imageUrl\":\"https://bratfest.kianm.net/api/images/brat\",\"multipliers\": \"[5, 10, 20, 50]\"},{\"id\": 1,\"name\": \"Chicken Brat\",\"price\": 400,\"imageUrl\": \"https://bratfest.kianm.net/api/images/chicken_brat\",\"multipliers\": \"[5, 10, 20, 50]\"},{\"id\": 2,\"name\": \"Veggie Brat\",\"price\": 400,\"imageUrl\":\"https://bratfest.kianm.net/api/images/veggie_brat\",\"multipliers\":\"[5, 10, 20, 50]\"},{\"id\": 3,\"name\":\"Hotdog\",\"price\":400,\"imageUrl\":\"https://bratfest.kianm.net/api/images/hotdog\",\"multipliers\":\" [5, 10, 20, 50]\"},{\"id\":4,\"name\":\"Beverage\",\"price\":400,\"imageUrl\":\"https://bratfest.kianm.net/api/images/beverage\",\"multipliers\": \"[]\"}]".data(using: .utf8)!)
            }
        }
    }
}

struct MainView_Previews: PreviewProvider {
    static var previews: some View {
        MainView()
    }
}
