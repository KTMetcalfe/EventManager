//
//  AuthorizeView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/22/22.
//

import SwiftUI
import BetterSafariView

struct AuthorizeView: View {
    @State private var startingWebAuthenticationSession = false
    
    @AppStorage("access_token") private var access_token = ""
    @AppStorage("isAuthorized") private var isAuthorized = false
    let defaults = UserDefaults.standard
    
    var body: some View {
        if (!access_token.isEmpty && !isAuthorized) {
            ProgressView()
        } else {
            Button("Authorize!") {
                startingWebAuthenticationSession = true
            }.webAuthenticationSession(isPresented: $startingWebAuthenticationSession) {
                WebAuthenticationSession(
                    url: URL(string: "https://em.kianm.net/oauth.php/authorize")!,
                    callbackURLScheme: "eventmanager"
                ) { callbackURL, error in
                    if (callbackURL != nil) {
                        if #available(iOS 16.0, *) {
                            let query = callbackURL?.query()
                            if ((query?.starts(with: "access_code")) != nil) {
                                let token_string = query?.split(by: "=")[1]
                                UserDefaults.standard.set(token_string, forKey: "access_token")
                            }
                        } else {
                            let query = callbackURL!.absoluteString
                            let token = String(query[query.index(query.firstIndex(of: "=") ?? query.startIndex, offsetBy: 1)...])
                            print(token)
                            UserDefaults.standard.set(token, forKey: "access_token")
                        }
                        SquareHelper().authorizeIfNeeded()
                    }
                }
            }
        }
    }
}

struct AuthorizeView_Previews: PreviewProvider {
    static var previews: some View {
        AuthorizeView()
    }
}
