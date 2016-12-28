//
//  FCAlertView.h
//  ShiftRide
//
//  Created by Nima Tahami on 2016-07-10.
//  Copyright © 2016 Nima Tahami. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>

@protocol FCAlertViewDelegate;

@interface FCAlertView : UIView <UITextFieldDelegate> {
    
    // Blur
    
    UIVisualEffectView *backgroundVisualEffectView;
    
    // Default UI adjustments
    
    CGFloat defaultHeight;
    CGFloat defaultSpacing;
    
    // AlertView & Contents
    
    UIView *alertView;
    UIView *alertViewContents;
    CAShapeLayer *circleLayer;
    
    // Customizations made to UI
    
    NSMutableArray *alertButtons;
    NSMutableArray *alertTextFields;
    NSInteger alertViewWithVector;
    NSString *doneTitle;
    UIImage *vectorImage;
    NSString *alertType;
    
    // Frames
    
    CGRect alertViewFrame;
    CGRect currentAVCFrames;
    CGRect descriptionLabelFrames;
    
    // Alert AudioPlayer
    
    AVAudioPlayer *player;

}

// Delegate

@property (nonatomic, weak) id<FCAlertViewDelegate> delegate;

// AlertView Title & Subtitle Text

@property (nonatomic, retain) NSString *title;
@property (nonatomic, retain) NSString *subTitle;
@property (nonatomic, retain) UIColor  *circleColor;
// AlertView Background

@property (nonatomic, retain) UIView *alertBackground;

// AlertView TextView

@property (nonatomic, retain) UITextField *textField;

// AlertView Customizations

@property CGFloat customHeight;
@property CGFloat customSpacing;

@property NSInteger numberOfButtons;
@property NSInteger autoHideSeconds;
@property CGFloat cornerRadius;

@property BOOL dismissOnOutsideTouch;
@property BOOL hideAllButtons;
@property BOOL hideDoneButton;
@property BOOL avoidCustomImageTint;
@property BOOL blurBackground;
@property BOOL bounceAnimations;

// Default Types of Alerts

- (void) makeAlertTypeWarning;
- (void) makeAlertTypeCaution;
- (void) makeAlertTypeSuccess;

// Play Sound with Alert

- (void) setAlertSoundWithFileName:(NSString *)filename;

// Presenting AlertView

- (void) showAlertInView:(UIViewController *)view withTitle:(NSString *)title withSubtitle:(NSString *)subTitle withCustomImage:(UIImage *)image withDoneButtonTitle:(NSString *)done andButtons:(NSArray *)buttons;

- (void) showAlertInWindow:(UIWindow *)window withTitle:(NSString *)title withSubtitle:(NSString *)subTitle withCustomImage:(UIImage *)image withDoneButtonTitle:(NSString *)done andButtons:(NSArray *)buttons;

- (void) showAlertWithTitle:(NSString *)title withSubtitle:(NSString *)subTitle withCustomImage:(UIImage *)image withDoneButtonTitle:(NSString *)done andButtons:(NSArray *)buttons;

- (void)setAlertViewAttributes:(NSString *)title withSubtitle:(NSString *)subTitle withCustomImage:(UIImage *)image withDoneButtonTitle:(NSString *)done andButtons:(NSArray *)buttons;

// Dismissing AlertView

- (void) dismissAlertView;

// Alert Action Block Method

typedef void (^FCActionBlock)(void);
@property (nonatomic, copy) FCActionBlock actionBlock;
@property (nonatomic, copy) FCActionBlock doneBlock;
- (void)addButton:(NSString *)title withActionBlock:(FCActionBlock)action;
- (void)doneActionBlock:(FCActionBlock)action;

// Alert TextField Block Method

typedef void (^FCTextReturnBlock)(NSString *text);
@property (nonatomic, copy) FCTextReturnBlock textReturnBlock;
- (void)addTextFieldWithPlaceholder:(NSString *)placeholder andTextReturnBlock:(FCTextReturnBlock)textReturn;

// Color Schemes

@property (nonatomic, retain) UIColor * colorScheme;
@property (nonatomic, retain)  UIColor * titleColor;
@property (nonatomic, retain)  UIColor * subTitleColor;

// Preset Flat Colors

@property (nonatomic, retain) UIColor * flatTurquoise;
@property (nonatomic, retain) UIColor * flatGreen;
@property (nonatomic, retain) UIColor * flatBlue;
@property (nonatomic, retain) UIColor * flatMidnight;
@property (nonatomic, retain) UIColor * flatPurple;
@property (nonatomic, retain) UIColor * flatOrange;
@property (nonatomic, retain) UIColor * flatRed;
@property (nonatomic, retain) UIColor * flatSilver;
@property (nonatomic, retain) UIColor * flatGray;

@end

@protocol FCAlertViewDelegate <NSObject>
@optional
- (void)FCAlertView:( FCAlertView *)alertView clickedButtonIndex:(NSInteger)index buttonTitle:(NSString *)title;
- (void)FCAlertViewDismissed:(FCAlertView *)alertView;
- (void)FCAlertViewWillAppear:(FCAlertView *)alertView;
- (void)FCAlertDoneButtonClicked:(FCAlertView *)alertView;

@end
