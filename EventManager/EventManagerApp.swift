//
//  EventManagerApp.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/2/22.
//

import SwiftUI
import SquareReaderSDK

@main
struct EventManagerApp: App {
    @State private var isSquareInitialized: Bool = false
    @UIApplicationDelegateAdaptor(AppDelegate.self) var appDelegate
    
    var body: some Scene {
        WindowGroup {
            ContentView()
                .background(Color(.systemBackground))
                .onAppear{
                    SquareViewController().requestLocationPermission()
                    SquareViewController().requestMicrophonePermission()
                }
        }
    }
}

class AppDelegate: NSObject, UIApplicationDelegate {
    var window: UIWindow?
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey : Any]? = nil) -> Bool {
        SQRDReaderSDK.initialize(applicationLaunchOptions: launchOptions)
        return true
    }
}
