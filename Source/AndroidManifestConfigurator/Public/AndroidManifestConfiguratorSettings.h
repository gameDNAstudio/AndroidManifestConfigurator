// Android Manifest Configurator
// Created by Patryk Stepniewski
// Copyright (c) 2014-2019 gameDNA Ltd. All Rights Reserved.

#pragma once

#include "AndroidManifestConfiguratorSettings.generated.h"

UENUM()
namespace EFeaturesType
{
	enum Type
	{
		/** Default value */
		Default,

		/** Application requires and cannot function without the declared feature. */
		Required,

		/** Prefers to have the feature but can function without it. */
		NotRequired
	};
}

UENUM()
namespace EAndroidKeyboardType
{
	enum Type
	{
		/** The application does not require a keyboard. (A keyboard requirement is not defined.) This is the default value. */
		undefined UMETA(DisplayName = "Undefined"),

		/** The application does not require a keyboard. */
		nokeys UMETA(DisplayName = "No Keys"),

		/** The application requires a standard QWERTY keyboard. */
		qwerty UMETA(DisplayName = "Qwerty"),

		/** The application requires a twelve-key keypad, like those on most phones — with keys for the digits from 0 through 9 plus star (*) and pound (#) keys. */
		twelvekey UMETA(DisplayName = "Twelve Key")
	};
}

UENUM()
namespace EAndroidNavigationType
{
	enum Type
	{
		/** The application does not require any type of navigation control. (The navigation requirement is not defined.) This is the default value. */
		undefined UMETA(DisplayName = "Undefined"),

		/** The application does not require a navigation control. */
		nonav UMETA(DisplayName = "No Nav"),

		/** The application requires a D-pad (directional pad) for navigation. */
		dpad UMETA(DisplayName = "D-pad"),

		/** The application requires a trackball for navigation. */
		trackball UMETA(DisplayName = "Trackball"),

		/** The application requires a navigation wheel. */
		wheel UMETA(DisplayName = "Wheel")
	};
}

UENUM()
namespace EAndroidTouchScreenType
{
	enum Type
	{
		/** The application doesn't require a touch screen. (The touch screen requirement is undefined.) This is the default value. */
		undefined UMETA(DisplayName = "Undefined"),

		/** The application doesn't require a touch screen. */
		notouch UMETA(DisplayName = "No Touch"),

		/** The application requires a touch screen that's operated with a stylus. */
		stylus UMETA(DisplayName = "Stylus"),

		/** The application requires a touch screen that can be operated with a finger. */
		finger UMETA(DisplayName = "Finger")
	};
}

UENUM()
namespace EAndroidTexturesCompression
{
	enum Type
	{
		Default,
		ETC1,
		ETC2,
		ATC,
		DXT,
		PVRTC,
		ASTC
	};
}


UCLASS(config = Engine, defaultconfig)
class UAndroidManifestConfiguratorSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UAndroidManifestConfiguratorSettings(const FObjectInitializer& ObjectInitializer);

	/** Indicates texture compression. Default means all types of texture compression. */
	UPROPERTY(Config, EditAnywhere, Category = "Textures", meta = (DisplayName = "Textures Compression"))
	TEnumAsByte<EAndroidTexturesCompression::Type> TexturesCompression;

	/** The app uses the OpenGL ES Android Extension Pack that is installed on the device. */
	UPROPERTY(Config, EditAnywhere, Category = "OpenGL", meta = (DisplayName = "OpenGL ES AEP"))
	TEnumAsByte<EFeaturesType::Type> bOpenGLAEP;

	/** Indicates whether the application supports smaller screen form-factors. A small screen is defined as one with a smaller aspect ratio than the "normal" (traditional HVGA) screen. An application that does not support small screens will not be available for small screen devices from external services (such as Google Play), because there is little the platform can do to make such an application work on a smaller screen. This is "true" by default. */
	UPROPERTY(Config, EditAnywhere, Category = "Screens", meta = (DisplayName = "Small Screens"))
	bool bSmallScreens;

	/** Indicates whether an application supports the "normal" screen form-factors. Traditionally this is an HVGA medium density screen, but WQVGA low density and WVGA high density are also considered to be normal. This attribute is "true" by default. */
	UPROPERTY(Config, EditAnywhere, Category = "Screens", meta = (DisplayName = "Normal Screens"))
	bool bNormalScreens;

	/** Indicates whether the application supports larger screen form-factors. A large screen is defined as a screen that is significantly larger than a "normal" handset screen, and thus might require some special care on the application's part to make good use of it, though it may rely on resizing by the system to fill the screen. The default value for this actually varies between some versions, so it's better if you explicitly declare this attribute at all times. Beware that setting it "false" will generally enable screen compatibility mode. */
	UPROPERTY(Config, EditAnywhere, Category = "Screens", meta = (DisplayName = "Large Screens"))
	bool bLargeScreens;

	/** Indicates whether the application supports extra large screen form-factors. An xlarge screen is defined as a screen that is significantly larger than a "large" screen, such as a tablet (or something larger) and may require special care on the application's part to make good use of it, though it may rely on resizing by the system to fill the screen. The default value for this actually varies between some versions, so it's better if you explicitly declare this attribute at all times. Beware that setting it "false" will generally enable screen compatibility mode. This attribute was introduced in API level 9. */
	UPROPERTY(Config, EditAnywhere, Category = "Screens", meta = (DisplayName = "XLarge Screens"))
	bool bXLargeScreens;

	/** Indicates whether the application includes resources to accommodate any screen density. For applications that support Android 1.6 (API level 4) and higher, this is "true" by default and you should not set it "false" unless you're absolutely certain that it's necessary for your application to work. The only time it might be necessary to disable this is if your app directly manipulates bitmaps. */
	UPROPERTY(Config, EditAnywhere, Category = "Screens", meta = (DisplayName = "Any Density"))
	bool bAnyDensity;

	/** Whether or not the application requires a five-way navigation control - "true" if it does, and "false" if not. A five-way control is one that can move the selection up, down, right, or left, and also provides a way of invoking the current selection. It could be a D-pad (directional pad), trackball, or other device. If an application requires a directional control, but not a control of a particular type, it can set this attribute to "true" and ignore the reqNavigation attribute. However, if it requires a particular type of directional control, it can ignore this attribute and set reqNavigation instead. */
	UPROPERTY(Config, EditAnywhere, Category = "Input", meta = (DisplayName = "Five-way navigation control"))
	bool bReqFiveWayNav;

	/** Whether or not the application requires a hardware keyboard - "true" if it does, and "false" if not. */
	UPROPERTY(Config, EditAnywhere, Category = "Input", meta = (DisplayName = "Hard keyboard"))
	bool bReqHardKeyboard;

	/** The type of keyboard the application requires, if any at all. This attribute does not distinguish between hardware and software keyboards. If a hardware keyboard of a certain type is required, specify the type here and also set the reqHardKeyboard attribute to "true". */
	UPROPERTY(Config, EditAnywhere, Category = "Input", meta = (DisplayName = "Hard keyboard type"))
	TEnumAsByte<EAndroidKeyboardType::Type> ReqKeyboardType;

	/** The navigation device required by the application, if any. */
	UPROPERTY(Config, EditAnywhere, Category = "Input", meta = (DisplayName = "Navigation device type"))
	TEnumAsByte<EAndroidNavigationType::Type> ReqNavigationType;

	/** The type of touch screen the application requires, if any at all. */
	UPROPERTY(Config, EditAnywhere, Category = "Input", meta = (DisplayName = "Touch screen type"))
	TEnumAsByte<EAndroidTouchScreenType::Type> ReqTouchScreen;

	/** The app is designed to show its UI on a set of screens inside a vehicle. The user interacts with the app using hard buttons, touch, rotary controllers, and mouse-like interfaces. The vehicle's screens usually appear in the center console or the instrument cluster of a vehicle. These screens usually have limited size and resolution. */
	UPROPERTY(Config, EditAnywhere, Category = "Hardware Type", meta = (DisplayName = "Automotive (for vehicles)"))
	TEnumAsByte<EFeaturesType::Type> bHardwareTypeAutomotive;

	/** The app is designed to show its UI on a television. This feature defines "television" to be a typical living room television experience: displayed on a big screen, where the user is sitting far away and the dominant form of input is something like a d-pad, and generally not using a mouse, pointer, or touch device. */
	UPROPERTY(Config, EditAnywhere, Category = "Hardware Type", meta = (DisplayName = "Television "))
	TEnumAsByte<EFeaturesType::Type> bHardwareTypeTelevision;

	/** The app is designed to show its UI on a watch. A watch is worn on the body, such as on the wrist. The user is very close to the device while interacting with it. */
	UPROPERTY(Config, EditAnywhere, Category = "Hardware Type", meta = (DisplayName = "Watch"))
	TEnumAsByte<EFeaturesType::Type> bHardwareTypeWatch;

	/** The app reads fingerprints using the device's biometric hardware. */
	UPROPERTY(Config, EditAnywhere, Category = "Fingerprint", meta = (DisplayName = "Biometric hardware for fingerprints"))
	TEnumAsByte<EFeaturesType::Type> bFingerprint;

	/** The app captures game controller input, either from the device itself or from a connected gamepad. */
	UPROPERTY(Config, EditAnywhere, Category = "Gamepad", meta = (DisplayName = "Gamepad"))
	TEnumAsByte<EFeaturesType::Type> bGamepad;

	/** The app uses the device's low-latency audio pipeline, which reduces lag and delays when processing sound input or output. */
	UPROPERTY(Config, EditAnywhere, Category = "Audio", meta = (DisplayName = "Audio low latency"))
	TEnumAsByte<EFeaturesType::Type> bAudioLowLatency;

	/** The app transmits sound using the device's speakers, audio jack, Bluetooth streaming capabilities, or a similar mechanism. */
	UPROPERTY(Config, EditAnywhere, Category = "Audio", meta = (DisplayName = "Audio output"))
	TEnumAsByte<EFeaturesType::Type> bAudioOutput;

	/** The app uses the device's high-end audio functionality and performance capabilities. */
	UPROPERTY(Config, EditAnywhere, Category = "Audio", meta = (DisplayName = "High-end audio functionalities"))
	TEnumAsByte<EFeaturesType::Type> bAudioPro;

	/** The app records audio using the device's microphone. */
	UPROPERTY(Config, EditAnywhere, Category = "Audio", meta = (DisplayName = "Microphone"))
	TEnumAsByte<EFeaturesType::Type> bAudioMicrophone;

	/** The app uses the device's Bluetooth features, usually to communicate with other Bluetooth-enabled devices. */
	UPROPERTY(Config, EditAnywhere, Category = "Bluetooth", meta = (DisplayName = "Bluetooth"))
	TEnumAsByte<EFeaturesType::Type> bBluetooth;

	/** The app uses the device's Bluetooth Low Energy radio features. */
	UPROPERTY(Config, EditAnywhere, Category = "Bluetooth", meta = (DisplayName = "Bluetooth Low Energy features"))
	TEnumAsByte<EFeaturesType::Type> bBluetoothLe;

	/** The app uses the device's back-facing camera. Devices with only a front-facing camera do not list this feature, so use the android.hardware.camera.any feature instead if your app can communicate with any camera, regardless of which direction the camera faces. */
	UPROPERTY(Config, EditAnywhere, Category = "Camera", meta = (DisplayName = "Camera"))
	TEnumAsByte<EFeaturesType::Type> bCamera;

	/** The app uses one of the device's cameras, or an external camera that the user connects to the device. Use this value instead of android.hardware.camera if your app does not require the camera to be a back-facing one. */
	UPROPERTY(Config, EditAnywhere, Category = "Camera", meta = (DisplayName = "Any camera"))
	TEnumAsByte<EFeaturesType::Type> bCameraAny;

	/** The app uses the autofocus feature that the device's camera supports. By using this feature, an app implies that it also uses the android.hardware.camera feature, unless this parent feature is declared with android:required="false". */
	UPROPERTY(Config, EditAnywhere, Category = "Camera", meta = (DisplayName = "Autofocus in camera"))
	TEnumAsByte<EFeaturesType::Type> bCameraAutofocus;

	/** The app uses the MANUAL_POST_PROCESSING feature that the device's camera supports. This feature allows your app to override the camera's auto white balance functionality. Use android.colorCorrection.transform, android.colorCorrection.gains, and an android.colorCorrection.mode of TRANSFORM_MATRIX. */
	UPROPERTY(Config, EditAnywhere, Category = "Camera", meta = (DisplayName = "Post-processing in camera"))
	TEnumAsByte<EFeaturesType::Type> bCameraPostProcessing;

	/** The app uses the MANUAL_SENSOR feature that the device's camera supports. This feature implies support for auto-exposure locking (android.control.aeLock), which allows the camera's exposure time and sensitivity to remain fixed at specific values. */
	UPROPERTY(Config, EditAnywhere, Category = "Camera", meta = (DisplayName = "Manual sensor in camera"))
	TEnumAsByte<EFeaturesType::Type> bCameraManualSensor;

	/** The app uses the RAW feature that the device's camera supports. This feature implies that the device can save DNG (raw) files and that the device's camera provides the DNG-related metadata necessary for your app to process these raw images directly. */
	UPROPERTY(Config, EditAnywhere, Category = "Camera", meta = (DisplayName = "RAW in camera"))
	TEnumAsByte<EFeaturesType::Type> bCameraRaw;

	/** The app communicates with an external camera that the user connects to the device. This feature does not guarantee, however, that the external camera is available for your app to use. */
	UPROPERTY(Config, EditAnywhere, Category = "Camera", meta = (DisplayName = "External camera"))
	TEnumAsByte<EFeaturesType::Type> bCameraExternal;

	/** The app uses the flash feature that the device's camera supports. By using this feature, an app implies that it also uses the android.hardware.camera feature, unless this parent feature is declared with android:required="false". */
	UPROPERTY(Config, EditAnywhere, Category = "Camera", meta = (DisplayName = "Flash in camera"))
	TEnumAsByte<EFeaturesType::Type> bCameraFlash;

	/** The app uses the device's front-facing camera. By using this feature, an app implies that it also uses the android.hardware.camera feature, unless this parent feature is declared with android:required="false". */
	UPROPERTY(Config, EditAnywhere, Category = "Camera", meta = (DisplayName = "Front camera"))
	TEnumAsByte<EFeaturesType::Type> bCameraFront;

	/** The app uses the FULL-level image-capturing support that at least one of the device's cameras provides. Cameras with FULL support provide burst-capture capabilities, per-frame control, and manual post-processing control. */
	UPROPERTY(Config, EditAnywhere, Category = "Camera", meta = (DisplayName = "Full camera support"))
	TEnumAsByte<EFeaturesType::Type> bCameraFull;

	/** The app uses the device's infrared (IR) capabilities, usually to communicate with other consumer IR devices. */
	UPROPERTY(Config, EditAnywhere, Category = "Infrared hardware", meta = (DisplayName = "IR support"))
	TEnumAsByte<EFeaturesType::Type> bConsumerIR;

	/** The app uses one or more features on the device for determining location, such as GPS location, network location, or cell location. */
	UPROPERTY(Config, EditAnywhere, Category = "Location", meta = (DisplayName = "Geolocation"))
	TEnumAsByte<EFeaturesType::Type> bLocation;

	/** The app uses precise location coordinates obtained from a Global Positioning System (GPS) receiver on the device. */
	UPROPERTY(Config, EditAnywhere, Category = "Location", meta = (DisplayName = "GPS for geolocation"))
	TEnumAsByte<EFeaturesType::Type> bLocationGPS;

	/** The app uses coarse location coordinates obtained from a network-based geolocation system supported on the device. */
	UPROPERTY(Config, EditAnywhere, Category = "Location", meta = (DisplayName = "Network-based geolocation"))
	TEnumAsByte<EFeaturesType::Type> bLocationNetwork;

	/** The app uses the device's Near-Field Communication (NFC) radio features. */
	UPROPERTY(Config, EditAnywhere, Category = "NFC", meta = (DisplayName = "NFC"))
	TEnumAsByte<EFeaturesType::Type> bNFC;

	/** The app uses motion readings from the device's accelerometer to detect the device's current orientation. For example, an app could use accelerometer readings to determine when to switch between portrait and landscape orientations. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Accelerometer sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorAccelerometer;

	/** The app uses the device's ambient (environmental) temperature sensor. For example, a weather app could report indoor or outdoor temperature. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Ambient temperature sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorAmbientTemperature;

	/** The app uses the device's barometer. For example, a weather app could report air pressure. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Barometer sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorBarometer;

	/** The app uses the device's magnetometer (compass). For example, a navigation app could show the current direction a user faces. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Compass sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorCompass;

	/** The app uses the device's gyroscope to detect rotation and twist, creating a six-axis orientation system. By using this sensor, an app can detect more smoothly whether it needs to switch between portrait and landscape orientations. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Gyroscope sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorGyroscope;

	/** The app uses the device's high fidelity (Hi-Fi) sensors. For example, a gaming app could detect the user's high-precision movements. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Hi-Fi sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorHifi;

	/** The app uses the device's heart rate monitor. For example, a fitness app could report trends in a user's heart rate over time. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Heartrate sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorHeartrate;

	/** The app uses the device's elcardiogram (ECG) heart rate sensor. For example, a fitness app could report more detailed information about a user's heart rate. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Heartrate ECG sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorHeartrateECG;

	/** The app uses the device's light sensor. For example, an app could display one of two different color schemes based on the ambient lighting conditions. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Light sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorLight;

	/** The app uses the device's proximity sensor. For example, a telephony app could turn off the device's screen when the app detects that the user is holding the device close to their body. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Proximity sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorProximity;

	/** The app uses the device's relative humidity sensor. For example, a weather app could use the humidity to calculate and report the current dewpoint. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Relative humidity sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorRelativeHumidity;

	/** The app uses the device's step counter. For example, a fitness app could report the number of steps a user needs to take to achieve their daily step count goal. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Step counter sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorStepCounter;

	/** The app uses the device's step detector. For example, a fitness app could use the time interval between steps to infer the type of exercise that the user is doing. */
	UPROPERTY(Config, EditAnywhere, Category = "Sensors", meta = (DisplayName = "Step detector sensor"))
	TEnumAsByte<EFeaturesType::Type> bSensorStepDetector;

	/** The app uses the device's telephony features, such as telephony radio with data communication services. */
	UPROPERTY(Config, EditAnywhere, Category = "Telephony", meta = (DisplayName = "Telephony"))
	TEnumAsByte<EFeaturesType::Type> bTelephony;

	/** The app uses the Code Division Multiple Access (CDMA) telephony radio system. */
	UPROPERTY(Config, EditAnywhere, Category = "Telephony", meta = (DisplayName = "Telephony CDMA"))
	TEnumAsByte<EFeaturesType::Type> bTelephonyCDMA;

	/** The app uses the Global System for Mobile Communications (GSM) telephony radio system. */
	UPROPERTY(Config, EditAnywhere, Category = "Telephony", meta = (DisplayName = "Telephony GSM"))
	TEnumAsByte<EFeaturesType::Type> bTelephonyGSM;

	/** The app uses the device's touchscreen capabilities for gestures that are more interactive than basic touch events, such as a fling. This is a superset of the android.hardware.faketouch feature. By default, your app requires this feature. As such, your app is not available to devices that provide only an emulated touch interface ("fake touch") by default. If you want to make your app available on devices that provide a fake touch interface (or even on devices that provide only a d-pad controller), you must explicitly declare that a touchscreen is not required by declaring android.hardware.touchscreen with android:required="false". You should add this declaration if your app uses—but does not require—a real touchscreen interface. If your app in fact requires a touch interface (to perform more advanced touch gestures such as fling), then you don't need to declare any touch interface features because they're required by default. However, it's best if you explicitly declare all features that your app uses. If you require more complex touch interaction, such as multi-finger gestures, you should declare that your app uses advanced touchscreen features.*/
	UPROPERTY(Config, EditAnywhere, Category = "Touchscreen", meta = (DisplayName = "TouchScreen"))
	TEnumAsByte<EFeaturesType::Type> bTouchscreen;

	/** The app uses the device's basic two-point multitouch capabilities, such as for pinch gestures, but the app does not need to track touches independently. This is a superset of the android.hardware.touchscreen feature. By using this feature, an app implies that it also uses the android.hardware.touchscreen feature, unless this parent feature is declared with android:required="false".*/
	UPROPERTY(Config, EditAnywhere, Category = "Touchscreen", meta = (DisplayName = "TouchScreen MultiTouch"))
	TEnumAsByte<EFeaturesType::Type> bTouchscreenMultitouch;

	/** The app uses the device's advanced multitouch capabilities for tracking two or more points independently. This feature is a superset of the android.hardware.touchscreen.multitouch feature. By using this feature, an app implies that it also uses the android.hardware.touchscreen.multitouch feature, unless this parent feature is declared with android:required="false". */
	UPROPERTY(Config, EditAnywhere, Category = "Touchscreen", meta = (DisplayName = "TouchScreen MultiTouch Distinct"))
	TEnumAsByte<EFeaturesType::Type> bTouchscreenMultitouchDistinct;

	/** The app uses the device's advanced multitouch capabilities for tracking five or more points independently. This feature is a superset of the android.hardware.touchscreen.multitouch feature. By using this feature, an app implies that it also uses the android.hardware.touchscreen.multitouch feature, unless this parent feature is declared with android:required="false". */
	UPROPERTY(Config, EditAnywhere, Category = "Touchscreen", meta = (DisplayName = "TouchScreen MultiTouch JazzHand"))
	TEnumAsByte<EFeaturesType::Type> bTouchscreenMultitouchJazzhand;

	/** The app uses basic touch interaction events, such as tapping and dragging. When declared as required, this feature indicates that the app is compatible with a device only if that device emulates a touchscreen ("fake touch" interface) or has an actual touchscreen. A device that offers a fake touch interface provides a user input system that emulates a subset of a touchscreen's capabilities. For example, a mouse or remote control could drive an on-screen cursor. If your app requires basic point and click interaction (in other words, it won't work with only a d-pad controller), you should declare this feature. Because this is the minimum level of touch interaction, you can also use an app that declares this feature on devices that offer more complex touch interfaces. */
	UPROPERTY(Config, EditAnywhere, Category = "Touchscreen", meta = (DisplayName = "FakeTouch"))
	TEnumAsByte<EFeaturesType::Type> bFakeTouch;

	/** The app tracks two or more distinct "fingers" on a fake touch interface. This is a superset of the android.hardware.faketouch feature. When declared as required, this feature indicates that the app is compatible with a device only if that device emulates distinct tracking of two or more fingers or has an actual touchscreen. Unlike the distinct multitouch defined by android.hardware.touchscreen.multitouch.distinct, input devices that support distinct multitouch with a fake touch interface don't support all two-finger gestures because the input in transformed to cursor movement on the screen. That is, single-finger gestures on such a device move a cursor, two-finger swipes cause single-finger touch events to occur, and other two-finger gestures trigger the corresponding two-finger touch events. A device that provides a two-finger touch trackpad for cursor movement can support this feature.*/
	UPROPERTY(Config, EditAnywhere, Category = "Touchscreen", meta = (DisplayName = "FakeTouch MultiTouch Distinct"))
	TEnumAsByte<EFeaturesType::Type> bFakeTouchMultiTouchDistinct;

	/** The app tracks five or more distinct "fingers" on a fake touch interface. This is a superset of the android.hardware.faketouch feature. When declared as required, this feature indicates that the app is compatible with a device only if that device emulates distinct tracking of five or more fingers or has an actual touchscreen. Unlike the distinct multitouch defined by android.hardware.touchscreen.multitouch.jazzhand, input devices that support jazzhand multitouch with a fake touch interface don't support all five-finger gestures because the input in transformed to cursor movement on the screen. That is, single-finger gestures on such a device move a cursor, multi-finger gestures cause single-finger touch events to occur, and other multi-finger gestures trigger the corresponding multi-finger touch events. A device that provides a five-finger touch trackpad for cursor movement can support this feature.*/
	UPROPERTY(Config, EditAnywhere, Category = "Touchscreen", meta = (DisplayName = "FakeTouch MultiTouch JazzHand"))
	TEnumAsByte<EFeaturesType::Type> bFakeTouchMultiTouchJazzhand;

	/** The app behaves as the USB device and connects to USB hosts. */
	UPROPERTY(Config, EditAnywhere, Category = "USB", meta = (DisplayName = "USB"))
	TEnumAsByte<EFeaturesType::Type> bUSBAccessory;

	/** The app uses the USB accessories that are connected to the device. The device serves as the USB host. */
	UPROPERTY(Config, EditAnywhere, Category = "USB", meta = (DisplayName = "USB host"))
	TEnumAsByte<EFeaturesType::Type> bUSBHost;

	/** The app uses 802.11 networking (Wi-Fi) features on the device. */
	UPROPERTY(Config, EditAnywhere, Category = "Wi-Fi", meta = (DisplayName = "Wi-Fi"))
	TEnumAsByte<EFeaturesType::Type> bWiFi;

	/** The app uses the Wi-Fi Direct networking features on the device. */
	UPROPERTY(Config, EditAnywhere, Category = "Wi-Fi", meta = (DisplayName = "Wi-Fi Direct"))
	TEnumAsByte<EFeaturesType::Type> bWiFiDirect;

	/** The app uses Session Initiation Protocol (SIP) services. By using SIP, the app can support internet telephony operations, such as video conferencing and instant messaging. */
	UPROPERTY(Config, EditAnywhere, Category = "Communication", meta = (DisplayName = "SIP services"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareSip;

	/** The app uses SIP-based Voice Over Internet Protocol (VoIP) services. By using VoIP, the app can support real-time internet telephony operations, such as two-way video conferencing. By using this feature, an app implies that it also uses the android.software.sip feature, unless this parent feature is declared with android:required="false". */
	UPROPERTY(Config, EditAnywhere, Category = "Communication", meta = (DisplayName = "VoIP"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareSipVoIP;

	/** The app displays content from the internet. */
	UPROPERTY(Config, EditAnywhere, Category = "Communication", meta = (DisplayName = "WebView"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareWebview;

	/** The app uses a new input method, which the developer defines in an InputMethodService. */
	UPROPERTY(Config, EditAnywhere, Category = "Custom Input Methods", meta = (DisplayName = "Software Input Methods"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareInputMethods;

	/** The app includes logic to handle a backup and restore operation. */
	UPROPERTY(Config, EditAnywhere, Category = "Device Management", meta = (DisplayName = "Backup"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareBackup;

	/** The app uses device administrators to enforce a device policy. */
	UPROPERTY(Config, EditAnywhere, Category = "Device Management", meta = (DisplayName = "Device administrators access"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareDeviceAdmin;

	/** The app supports secondary users and managed profiles. */
	UPROPERTY(Config, EditAnywhere, Category = "Device Management", meta = (DisplayName = "Managed users"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareManagedUsers;

	/** The app can permanently remove users and their associated data. */
	UPROPERTY(Config, EditAnywhere, Category = "Device Management", meta = (DisplayName = "Removing users"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareSecurelyRemovesUsers;

	/** The app includes logic to handle results from the device's verified boot feature, which detects whether the device's configuration changes during a restart operation. */
	UPROPERTY(Config, EditAnywhere, Category = "Device Management", meta = (DisplayName = "Software verified boot"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareVerifiedBoot;

	/** The app connects to musical instruments or outputs sound using the Musical Instrument Digital Interface (MIDI) protocol. */
	UPROPERTY(Config, EditAnywhere, Category = "Media Software", meta = (DisplayName = "MIDI"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareMidi;

	/** The app includes commands for printing documents displayed on the device. */
	UPROPERTY(Config, EditAnywhere, Category = "Media Software", meta = (DisplayName = "Printing"))
	TEnumAsByte<EFeaturesType::Type> bSoftwarePrint;

	/** The app presents a UI that is designed for viewing on a large screen, such as a television. */
	UPROPERTY(Config, EditAnywhere, Category = "Media Software", meta = (DisplayName = "Large screen (television)"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareLeanback;

	/** The app streams live television programs. */
	UPROPERTY(Config, EditAnywhere, Category = "Media Software", meta = (DisplayName = "Live streaming TV programs"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareLiveTV;

	/** The app uses or provides App Widgets and should be installed only on devices that include a Home screen or similar location where users can embed App Widgets. */
	UPROPERTY(Config, EditAnywhere, Category = "Screen interface", meta = (DisplayName = "App Widgets"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareAppWidgets;

	/** The app behaves as a replacement to the device's Home screen. */
	UPROPERTY(Config, EditAnywhere, Category = "Screen interface", meta = (DisplayName = "Home Screen"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareHomeScreen;

	/** The app uses or provides wallpapers that include animation. */
	UPROPERTY(Config, EditAnywhere, Category = "Screen interface", meta = (DisplayName = "Live Wallpaper"))
	TEnumAsByte<EFeaturesType::Type> bSoftwareLiveWallpaper;
};
