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
            VStack {
                List(0..<25) { column in
                    Button("Brat") {
                    }
                    .buttonStyle(.plain)
                }
            }
        } else {
            GeometryReader { geometry in
                ZStack(alignment: .topLeading) {
                    HStack {
                        ZStack {
                            Group {
                                ZStack {
                                    ForEach(0..<25) { index in
                                        Color(.systemGray2)
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
                                    ForEach(outJson) { item in
                                        Button(action: {print("test")}) {
                                            VStack {
                                                AsyncImage(url: URL(string: "https://em.kianm.net/files/item_images/Bratfest/" + String(item.ID) + ".jpg")) { phase in
                                                    if let image = phase.image {
                                                        image
                                                            .resizable()
                                                            .aspectRatio(contentMode: .fill)
                                                    } else if phase.error != nil {
                                                        Color(.systemGray)
                                                    } else {
                                                        ProgressView()
                                                    }
                                                }
                                                .frame(
                                                    width: geometry.size.width * 0.12,
                                                    height: geometry.size.height * 0.1
                                                )
                                                Text(item.name)
                                            }
                                            .frame(
                                                width: geometry.size.width * 0.12,
                                                height: geometry.size.height * 0.15
                                            )
                                            .contentShape(RoundedRectangle(cornerRadius: 12))
                                        }
                                        .background(.gray)
                                        .cornerRadius(12)
                                        .buttonStyle(.plain)
                                        .position(
                                            x: (geometry.size.width * 0.14 * CGFloat(item.posX)) - (geometry.size.width * 0.09 * 0.5),
                                            y: (geometry.size.height * 0.18 * CGFloat(item.posY)) - (geometry.size.height * 0.2 * 0.5)
                                        )
                                    }
                                }
                            }
                            if showKeypad {
                                keypad(geometry: geometry)
                            }
                        }
                        .frame(
                            width: geometry.size.width * 0.75,
                            height: geometry.size.height * 0.96
                        )
                        VStack {
                            List(outJson) { item in
                                Text("X: " + String(item.posX) + "  Y: " + String(item.posY))
                            }
                        }
                        .frame(
                            width: geometry.size.width * 0.25,
                            height: geometry.size.height * 0.96
                        )
                    }
                    HStack() {
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
                        width: geometry.size.width,
                        height: geometry.size.height * 0.08,
                        alignment: .top
                    )
                    .background(.gray)
                    .position(
                        x: geometry.size.width * 0.5,
                        y: geometry.size.height * 0.96
                    )
                }
            }
            .font(.system(size: 24))
        }
    }
}

@available(iOS 16.0, *)
struct keypad: View {
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
    func makeBody(configuration: Self.Configuration) -> some View {
        configuration.label
            .scaleEffect(configuration.isPressed ? 1.5 : 1)
    }
}

@available(iOS 16.0, *)
struct GridView_Previews: PreviewProvider {
    static var previews: some View {
        GridView(outJson: .constant(Helper.load(name: "BratTent")))
    }
}
