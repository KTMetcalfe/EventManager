//
//  GridView.swift
//  EventManager
//
//  Created by Kian Metcalfe on 6/8/22.
//

import SwiftUI

@available(iOS 16.0, *)
struct GridView: View {
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
                ZStack {
                    HStack {
                        Grid(horizontalSpacing: 30, verticalSpacing: 30) {
                            ForEach(0..<5) { row in
                                GridRow {
                                    ForEach(0..<5) { column in
                                        Button(action: {print("test")}) {
                                            VStack {
                                                AsyncImage(url: URL(string: "https://em.kianm.net/files/item_images/Bratfest/19.jpg")) { phase in
                                                    if let image = phase.image {
                                                        image
                                                            .resizable()
                                                            .aspectRatio(contentMode: .fill)
                                                    } else if phase.error != nil {
                                                        Color.red
                                                    } else {
                                                        ProgressView()
                                                    }
                                                }
                                                .frame(
                                                    width: geometry.size.width * 0.12,
                                                    height: geometry.size.height * 0.1
                                                )
                                                Text("Brat")
                                            }
                                            .frame(
                                                width: geometry.size.width * 0.12,
                                                height: geometry.size.height * 0.15
                                            )
                                        }
                                        .background(.gray)
                                        .cornerRadius(12)
                                        .buttonStyle(.plain)
                                    }
                                }
                            }
                        }
                        .font(.system(size: 24))
                        .frame(
                            width: geometry.size.width * 0.75,
                            height: geometry.size.height,
                            alignment: .top
                        )
                        List(0..<5) { _ in
                            Button(action: {}) {
                                Text("Test")
                            }
                        }
                        .frame(
                            width: geometry.size.width * 0.25,
                            height: geometry.size.height
                        )
                    }
                    HStack() {
                        ForEach(0..<5) {_ in
                            Button(action: {}) {
                               Text("Option")
                                    .padding()
                            }
                            .buttonStyle(.plain)
                        }
                    }
                    .frame(
                        width: geometry.size.width,
                        height: geometry.size.height * 0.05
                    )
                    .background(.gray)
                    .position(
                        x: geometry.size.width * 0.5,
                        y: geometry.size.height
                    )
                }
            }
        }
    }
}

@available(iOS 16.0, *)
struct GridView_Previews: PreviewProvider {
    static var previews: some View {
        GridView()
    }
}
