//
//  PreviewHelper.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/15/22.
//

import Foundation

class Helper {
    static func load<T: Codable>(name: String) -> [T] {
        if let path = Bundle.main.path(forResource: name, ofType: "json") {
            do {
                let data = try Data(contentsOf: URL(fileURLWithPath: path))
                let results = try JSONDecoder().decode([T].self, from: data)
                return results
            } catch {
                return []
            }
        }
        
        return []
    }
    
}
