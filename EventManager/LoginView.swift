//
//  LoginView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/2/22.
//

import SwiftUI
import Combine

import Foundation

extension String {

    func fromBase64() -> String? {
        guard let data = Data(base64Encoded: self) else {
            return nil
        }

        return String(data: data, encoding: .utf8)
    }

    func toBase64() -> String {
        return Data(self.utf8).base64EncodedString()
    }

}

struct LoginView: View {
    @State private var username: String = ""
    @State private var password: String = ""
    @State private var location: String = ""
    
    @AppStorage("isLoggedIn") private var isLoggedIn = false
    
    struct Login: Codable {
        var verified: Bool?
        var location_name: String?
        var error: String?
    }
    
    func decode(outData: Data) -> Login {
        return try! JSONDecoder().decode(Login.self, from: outData)
    }
    
    func verifyLogin() {
        let url = URL(string: "https://em.kianm.net/index.php/login/verify")!

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
            
            if (decode(outData: data).verified == true) {
                let defaults = UserDefaults.standard
                defaults.set(username, forKey: "username")
                defaults.set(password, forKey: "password")
                defaults.set(location, forKey: "location")
                defaults.set(decode(outData: data).location_name, forKey: "location_name")
                defaults.set(true, forKey: "isLoggedIn")
            }
        }
        task.resume()
    }
    
    var body: some View {
        Form {
            Text("Jamboree")
                .padding()
                .font(.largeTitle)
                .frame(maxWidth: .infinity, alignment: .center)
                .listRowBackground(Color.clear)
            Section {
                TextField("Username", text: $username)
                    .font(.title3)
                    .padding()
                    .multilineTextAlignment(.center)
                    .textInputAutocapitalization(.never)
                    .disableAutocorrection(true)
                SecureField("Passowrd", text: $password)
                    .font(.title3)
                    .padding()
                    .multilineTextAlignment(.center)
                    .textInputAutocapitalization(.never)
                    .disableAutocorrection(true)
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
                    if (!username.isEmpty && !password.isEmpty && !location.isEmpty) {
                        verifyLogin()
                    }
                }
                .font(.title2)
                Spacer()
            }
        }
//        .frame(maxHeight: 350)
//        .cornerRadius(15)
//        .padding()
    }
}

struct LoginView_Previews: PreviewProvider {
    static var previews: some View {
        LoginView()
    }
}
