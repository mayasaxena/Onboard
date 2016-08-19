//
//  OnboardingContentViewController.h
//  Onboard
//
//  Created by Mike on 8/17/14.
//  Copyright (c) 2014 Mike Amaral. All rights reserved.
//

#import <UIKit/UIKit.h>
@import AVKit;

@class OnboardingViewController;
@class OnboardingContentViewController;

@protocol OnboardingContentViewControllerDelegate <NSObject>

@required
- (void)setNextPage:(OnboardingContentViewController *)contentVC;
- (void)setCurrentPage:(OnboardingContentViewController *)contentVC;

@end

extern NSString * const kOnboardMainTextAccessibilityIdentifier;
extern NSString * const kOnboardSubTextAccessibilityIdentifier;
extern NSString * const kOnboardActionButtonAccessibilityIdentifier;

typedef void (^action_callback)(OnboardingViewController *onboardController);


@interface OnboardingContentViewController : UIViewController

@property (nonatomic, weak) OnboardingViewController<OnboardingContentViewControllerDelegate> *delegate;

/**
 * @brief Determines if the next page is automatically shown when the action button is pressed.
 */
@property (nonatomic) BOOL movesToNextViewController;


/**
 * @brief The title text
 */
@property (nonatomic, strong) NSString *titleText;


/**
 * @brief The body text.
 */
@property (nonatomic, strong) NSString *body;


/**
 * @brief The top icon image
 */
@property (nonatomic, strong) UIImage *image;


/**
 * @brief The text of the button used to call the action handler if one was provided.
 */
@property (nonatomic, strong) NSString *buttonText;


/**
 * @brief The URL for the background video
 */
@property (nonatomic, strong) NSURL *videoURL;


/**
 * @brief The width of the icon image view.
 */
@property (nonatomic) CGFloat iconWidth;


/**
 * @brief The height of the icon image view.
 */
@property (nonatomic) CGFloat iconHeight;


/**
 * @brief The padding between the top of the screen and the top of the icon image view.
 */
@property (nonatomic) CGFloat topPadding;


/**
 * @brief The padding between the icon image view and the title label.
 */
@property (nonatomic) CGFloat underIconPadding;


/**
 * @brief The padding between the title label and the body label;
 */
@property (nonatomic) CGFloat underTitlePadding;


/**
 * @brief The padding between the bottom of the action button and the page control.
 */
@property (nonatomic) CGFloat bottomPadding;


/**
 * @brief The padding between the bottom of the screen and the page control.
 */
@property (nonatomic) CGFloat underPageControlPadding;


/**
 * @brief The block executed when the action button is pressed.
 */
@property (nonatomic, copy) action_callback buttonActionHandler;


/**
 * @brief The block executed when the content view controller's viewWillAppear method is called.
 */
@property (nonatomic, copy) dispatch_block_t viewWillAppearBlock;


/**
 * @brief The block executed when the content view controller's viewDidAppear method is called.
 */
@property (nonatomic, copy) dispatch_block_t viewDidAppearBlock;


/**
 * @brief The block executed when the content view controller's viewWillDisappear method is called.
 */
@property (nonatomic, copy) dispatch_block_t viewWillDisappearBlock;


/**
 * @brief The block executed when the content view controller's viewDidDisappear method is called.
 */
@property (nonatomic, copy) dispatch_block_t viewDidDisappearBlock;


/**
 * @brief The movie player controller used to play background movies.
 */
@property (nonatomic, strong) AVPlayerViewController *moviePlayerController;


@property (nonatomic, strong) IBOutlet UIImageView *iconImageView;
@property (nonatomic, strong) IBOutlet UILabel *titleLabel;
@property (nonatomic, strong) IBOutlet UILabel *bodyLabel;
@property (nonatomic, strong) IBOutlet UIButton *actionButton;


/**
 * @brief Convenience class initializer for creating an onboarding content view controller.
 * @return An instance of OnboardingViewController with the provided information.
 */
+ (instancetype)contentWithTitle:(NSString *)title body:(NSString *)body image:(UIImage *)image buttonText:(NSString *)buttonText action:(dispatch_block_t)action;


/**
 * @brief Initializer for creating an onboarding content view controller.
 * @return An instance of OnboardingViewController with the provided information.
 */
- (instancetype)initWithTitle:(NSString *)title body:(NSString *)body image:(UIImage *)image buttonText:(NSString *)buttonText action:(dispatch_block_t)action;


/**
 * @brief Convenience class initializer for creating an onboarding content view controller with an action_callback block.
 * @return An instance of OnboardingViewController with the provided information.
 */
+ (instancetype)contentWithTitle:(NSString *)title body:(NSString *)body image:(UIImage *)image buttonText:(NSString *)buttonText actionBlock:(action_callback)actionBlock;


/**
 * @brief Convenience class initializer for creating an onboarding content view controller with a video.
 * @return An instance of OnboardingViewController with the provided information.
 */
+ (instancetype)contentWithTitle:(NSString *)title body:(NSString *)body videoURL:(NSURL *)videoURL buttonText:(NSString *)buttonText action:(dispatch_block_t)action;


/**
 * @brief Initializer for creating an onboarding content view controller with a video.
 * @return An instance of OnboardingViewController with the provided information.
 */
- (instancetype)initWithTitle:(NSString *)title body:(NSString *)body videoURL:(NSURL *)videoURL buttonText:(NSString *)buttonText action:(dispatch_block_t)action;


/**
 * @brief Convenience class initializer for creating an onboarding content view controller with a video and an action_callback block.
 * @return An instance of OnboardingViewController with the provided information.
 */
+ (instancetype)contentWithTitle:(NSString *)title body:(NSString *)body videoURL:(NSURL *)videoURL buttonText:(NSString *)buttonText actionBlock:(action_callback)actionBlock;


/**
 * @brief Initializer for creating an onboarding content view controller with a video and an action_callback block.
 * @return An instance of OnboardingViewController with the provided information.
 */
- (instancetype)initWithTitle:(NSString *)title body:(NSString *)body image:(UIImage *)image buttonText:(NSString *)buttonText actionBlock:(action_callback)actionBlock;


/**
 * @brief Initializer for creating an onboarding content view controller with a video and an action_callback block.
 * @return An instance of OnboardingViewController with the provided information.
 */
- (instancetype)initWithTitle:(NSString *)title body:(NSString *)body image:(UIImage *)image videoURL:videoURL buttonText:(NSString *)buttonText actionBlock:(action_callback)actionBlock;


/**
 * @brief Method used to update the alpha value for all floating subviews (image, title, body, etc.)
 */
- (void)updateAlphas:(CGFloat)newAlpha;

@end
