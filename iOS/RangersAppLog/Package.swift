// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "RangersAppLog",
    platforms: [.macOS(.v10_13),
                .iOS(.v12)],
    products: [
        .library(
            name: "RangersAppLog",
            targets: ["RangersAppLog"]),
    ],
    targets: [
        .target(
            name: "RangersAppLog",
            dependencies: [
                .target(name: "VolcEngineEncryptor"),
                .target(name: "RangersAppLogFramework"),
            ],
            path: "RangersAppLog",
            resources: [
                .process("h5bridge-wkwebview.js")
            ],
            linkerSettings: [
                .linkedLibrary("z"),
                .linkedLibrary("sqlite3"),
                .linkedFramework("CoreGraphics"),
                .linkedFramework("Foundation"),
                .linkedFramework("Security"),
                .linkedFramework("CoreTelephony"),
                .linkedFramework("CoreFoundation"),
                .linkedFramework("SystemConfiguration"),
                .linkedFramework("WebKit"),
                .linkedFramework("UIKit", .when(platforms: [.iOS])),
                .linkedFramework("AppKit", .when(platforms: [.macOS]))
            ]
            
        ),
        .binaryTarget(
            name: "VolcEngineEncryptor",
            path: "./Frameworks/VolcEngineEncryptor.xcframework"
        ),
        .binaryTarget(
            name: "RangersAppLogFramework",
            path: "./Frameworks/RangersAppLog.xcframework"
        ),
        .testTarget(
            name: "RangersAppLogTests",
            dependencies: ["RangersAppLog"]
        ),
    ]
)
