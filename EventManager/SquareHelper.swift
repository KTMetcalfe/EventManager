//
//  SquareHelper.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/22/22.
//

import Foundation
import SwiftUI
import SquareReaderSDK
import CoreLocation
import AVFAudio

struct AuthResponse: Codable {
    let authorization_code: String?
    let expires_at: String?
}

class SquareHelper {
    private let LOCATION_ID = "3BMMCM8M9ZNAZ"
    
    @AppStorage("access_token") private var access_token = ""
    
    func getAuthCode(complete: @escaping (String) -> Void) {
        if access_token.isEmpty {
            // Make request for new access token
            UserDefaults.resetStandardUserDefaults()
        }
        
        let url = URL(string: "https://connect.squareup.com/mobile/authorization-code")!

        var request = URLRequest(url: url)
        request.httpMethod = "POST"
        request.setValue("application/json", forHTTPHeaderField: "Accept")
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        request.setValue("Bearer " + access_token, forHTTPHeaderField: "Authorization")
        request.httpBody = ("{\"location_id\": \"" + LOCATION_ID + "\"}").data(using: .utf8)
        
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

            print("OUPUT: " + string)
            let outJson = try! JSONDecoder().decode(AuthResponse.self, from: data)
            complete(outJson.authorization_code ?? "NO CODE")
        }
        task.resume()
    }
    
    func authorizeIfNeeded() {
        if !SQRDReaderSDK.shared.isAuthorized {
            getAuthCode() { (authCode) in
                DispatchQueue.main.async {
                    SQRDReaderSDK.shared.authorize(withCode: authCode) { _, error in
                        if let authError = error {
                            // Handle the error
                            print(authError)
                            UserDefaults.standard.set(false, forKey: "isAuthorized")
                        } else {
                            // Proceed to the main application interface.
                            UserDefaults.standard.set(true, forKey: "isAuthorized")
                        }
                    }
                }
            }
        }
    }
}

// Custom UIViewController
class SquareViewController: UIViewController {
    private lazy var locationManager = CLLocationManager()

    func requestLocationPermission() {
        switch locationManager.authorizationStatus {
            case .notDetermined:
                locationManager.requestWhenInUseAuthorization()
            case .restricted, .denied:
                print("Show UI directing the user to the iOS Settings app")
            case .authorizedAlways, .authorizedWhenInUse:
                print("Location services have already been authorized.")
            @unknown default:
                fatalError()
        }
    }
    
    func requestMicrophonePermission() {
        // Note: The microphone permission prompt will not be displayed
        // when running on the simulator
        AVAudioSession.sharedInstance().requestRecordPermission { authorized in
            if !authorized {
                print("Show UI directing the user to the iOS Settings app")
            }
        }
    }
}
