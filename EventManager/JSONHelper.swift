//
//  PreviewHelper.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/15/22.
//

import Foundation

struct Item: Codable {
    let id: Int
    let name: String
    let price: Int
    let multipliers: String
    let locations: String
    let posX: Int
    let posY: Int
}

extension Item: Identifiable {
    var ID: Int { return id }
}

class Helper {
    static func load (name: String) -> [Item] {
        if let path = Bundle.main.path(forResource: name, ofType: "json") {
            do {
                let data = try Data(contentsOf: URL(fileURLWithPath: path))
                let results = try JSONDecoder().decode([Item].self, from: data)
                return results
            } catch {
                return []
            }
        }
        
        return []
    }
    
    static func decode<out: Codable> (outData: Data) -> [out] {
        do {
            let outJson = try JSONDecoder().decode([out].self, from: outData)
            return outJson
        } catch {
            return []
        }
    }
}
