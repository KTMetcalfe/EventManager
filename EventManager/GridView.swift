//
//  GridView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/8/22.
//

import SwiftUI

@available(iOS 16.0, *)
struct GridView: View {
    @State private var showKeypad: Bool = false
    
    @Binding var outJson: [Item]
    
    var body: some View {
        if UIDevice.current.userInterfaceIdiom == .phone {
            // List for iphone devices
            VStack {
                List(outJson) { item in
                    Button(item.name + String(item.price)) {
                    }
                    .buttonStyle(.plain)
                }
            }
        } else {
            // List for all non-iphones
            GeometryReader { geometry in
                VStack(alignment: .leading, spacing: 0) {
                    // Main stack
                    HStack(spacing: 0) {
                        // Item grid and keypad
                        ZStack {
                            ItemGrid(itemList: $outJson, geometry: geometry)
                            if showKeypad {
                                Keypad(geometry: geometry)
                            }
                        }
                        // Checkout list
                        CheckoutList()
                        .frame(
                            width: geometry.size.width * 0.25
                        )
                        .background(Color(.secondarySystemBackground))
                    }
                    // Navigation stack
                    HStack {
                        Button(action: {
                            showKeypad = false
                        }) {
                           Text("Checkout")
                                .padding()
                        }
                        .buttonStyle(.plain)
                        Button(action: {
                            showKeypad = true
                        }) {
                           Text("Keypad")
                                .padding()
                        }
                        .buttonStyle(.plain)
                    }
                    .frame(
                        width: geometry.size.width
                    )
                    .background(Color(.systemGray2))
                }
            }
            .font(.system(size: 22))
        }
    }
}

struct CheckoutItem: Codable {
    let id: Int
    let name: String
    var price: Int
    var count: Int
}

extension CheckoutItem: Identifiable {
    var ID: Int { return id }
}

class CheckoutFunction: ObservableObject {
    @Published var checkoutList = [CheckoutItem]()
    
    func addItem(id: Int, name: String, price: Int, amount: Int) {
        if (checkoutList.contains(where: {$0.id == id})) {
            let index = checkoutList.firstIndex(where: {$0.id == id})
            checkoutList[index!].price += price;
            checkoutList[index!].count += amount;
        } else {
            checkoutList.append(CheckoutItem.init(id: id, name: name, price: price, count: amount))
        }
    }
}

struct CheckoutList: View {
    @EnvironmentObject var checkoutModel: CheckoutFunction
    
    var body: some View {
        if (checkoutModel.checkoutList.isEmpty) {
            Color(.secondarySystemBackground)
        } else {
            VStack(spacing: 0) {
                List(checkoutModel.checkoutList) { item in
                    HStack {
                        Text(item.name + " x" + String(item.count))
                        Text(Helper.formatPrice(price: item.price))
                    }
                }
                NavigationLink("Checkout") {
                    CheckoutView().environmentObject(checkoutModel)
                }.padding()
            }
        }
    }
}

struct ItemGrid: View {
    @Binding var itemList: [Item]
    @EnvironmentObject var checkoutModel: CheckoutFunction
    let geometry: GeometryProxy
    
    var body: some View {
        ZStack {
            BackgroundGrid(geometry: geometry)
            ForEach(itemList) { item in
                Button(action: {
                    print(item.name)
                    checkoutModel.addItem(id: item.id, name: item.name, price: item.price, amount: 1)
                }) {
                    VStack(spacing: 0) {
                        AsyncImage(url: URL(string: "https://em.kianm.net/files/item_images/Bratfest/" + String(item.ID) + ".jpg")) { phase in
                            if let image = phase.image {
                                image
                                    .resizable()
                                    .aspectRatio(contentMode: .fill)
                                    .frame(
                                        width: geometry.size.width * 0.12,
                                        height: geometry.size.height * 0.1125
                                    )
                                    .clipped()
                            } else if phase.error != nil {
                                Color(.systemGray)
                            } else {
                                ProgressView()
                            }
                        }
                        .frame(
                            width: geometry.size.width * 0.12,
                            height: geometry.size.height * 0.1125
                        )
                        Text(item.name)
                    }
                    .frame(
                        width: geometry.size.width * 0.12,
                        height: geometry.size.height * 0.15
                    )
                    .contentShape(RoundedRectangle(cornerRadius: 12))
                }
                .background(Color(.systemGray))
                .cornerRadius(12)
                .buttonStyle(ScaleButtonStyle(scale: 1.1))
                .position(
                    x: (geometry.size.width * 0.14 * CGFloat(item.posX)) - (geometry.size.width * 0.09 * 0.5),
                    y: (geometry.size.height * 0.18 * CGFloat(item.posY)) - (geometry.size.height * 0.2 * 0.5)
                )
            }
        }
    }
}

struct BackgroundGrid: View {
    let geometry: GeometryProxy
    
    var body: some View {
        ForEach(0..<25) { index in
            Color(.systemGray6)
            .cornerRadius(12)
            .frame(
                width: geometry.size.width * 0.12,
                height: geometry.size.height * 0.15
            )
            .position(
                x: (geometry.size.width * 0.14 * CGFloat((index % 5) + 1)) - (geometry.size.width * 0.09 * 0.5),
                y: (geometry.size.height * 0.18 * CGFloat((index / 5) + 1)) - (geometry.size.height * 0.2 * 0.5)
            )
        }
    }
}

@available(iOS 16.0, *)
struct Keypad: View {
    let geometry: GeometryProxy
    
    var body: some View {
        Color(.systemGray3).overlay(content: {
            Grid(horizontalSpacing: 25, verticalSpacing: 25) {
                ForEach(0..<4) { _ in
                    GridRow {
                        ForEach(0..<3) { _ in
                            Button(action: {
                                print("Click!")
                            }) {
                                Text("0")
                                .frame(
                                    width: geometry.size.width * 0.15,
                                    height: geometry.size.height * 0.15
                                )
                                .contentShape(RoundedRectangle(cornerRadius: 12))
                            }
                            .background(Color(.systemGray))
                            .cornerRadius(12)
                            .buttonStyle(ScaleButtonStyle())
                        }
                    }
                }
            }
        })
    }
    
}

struct ScaleButtonStyle: ButtonStyle {
    var scale: Double = 1.5
    func makeBody(configuration: Self.Configuration) -> some View {
        configuration.label
            .scaleEffect(configuration.isPressed ? scale : 1)
    }
}

@available(iOS 16.0, *)
struct GridView_Previews: PreviewProvider {
    static var previews: some View {
        GridView(outJson: .constant(Helper.load(name: "BratTent")))
            .environmentObject(CheckoutFunction())
    }
}
