//
//  OnboardingViewController.h
//  Onboard
//
//  Created by Mike on 8/17/14.
//  Copyright (c) 2014 Mike Amaral. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OnboardingContentViewController.h"
@import AVKit;

@interface OnboardingViewController : UIViewController <UIPageViewControllerDataSource, UIPageViewControllerDelegate, UIScrollViewDelegate, OnboardingContentViewControllerDelegate>

/**
 * @brief The onboarding content view controllers.
 */
@property (nonatomic, strong) NSArray *viewControllers;


/**
 * @brief The background image that will be visible through the content view controllers.
 */
@property (nonatomic, strong) UIImage *backgroundImage;


/**
 * @brief Determines whether or not the background will be masked. The default value of this property is YES.
 */
@property (nonatomic) BOOL shouldMaskBackground;


/**
 * @brief Determines whether or not the background will be blurred. The default value of this property is NO;
 */
@property (nonatomic) BOOL shouldBlurBackground;


/**
 * @brief Determines whether or not the contents on screen will fade as the user swipes between pages. The default value of this property is NO.
 */
@property (nonatomic) BOOL shouldFadeTransitions;


/**
 * @brief Determines whether or not the background will be masked. The default value of this property is NO.
 */
@property (nonatomic) BOOL fadePageControlOnLastPage;


/**
 * @brief Determines whether or not the skip button will fade away on the last page. The default value of this property is NO.
 */
@property (nonatomic) BOOL shouldChangeButtonsOnLastPage;

/**
 * @brief A block that will be executed when the skip button is pressed.
 */
@property (nonatomic, strong) dispatch_block_t leftButtonHandler;


/**
 * @brief A block that will be executed when the skip button is pressed.
 */
@property (nonatomic, strong) dispatch_block_t rightButtonHandler;


/**
 * @brief Determines whether or not swiping is enabled between pages. The default value of this property is YES.
 */
@property (nonatomic) BOOL swipingEnabled;


/**
 * @brief Determines whether or not the page control will be visible.
 */
@property (nonatomic, strong) IBOutlet UIPageControl *pageControl;


/**
 * @brief The button on the left of the page control
 */
@property (nonatomic, strong) UIButton *leftButton;


/**
 * @brief The button on the right of the page control
 */
@property (nonatomic, strong) UIButton *rightButton;


/**
 * @brief The button on the left of the page control on the last page only
 */
@property (nonatomic, strong) UIButton *lastPageLeftButton;


/**
 * @brief The button on the right of the page control on the last page only
 */
@property (nonatomic, strong) UIButton *lastPageRightButton;


@property (nonatomic, strong) IBOutlet UIButton *currentLeftButton;
@property (nonatomic, strong) IBOutlet UIButton *currentRightButton;

/**
 * @brief Determines whether or not the movie player stops playing when the view disappears.
 */
@property (nonatomic) BOOL stopMoviePlayerWhenDisappear;


/**
 * @brief The movie player controller used to play background movies.
 */
@property (nonatomic, strong) AVPlayerViewController *moviePlayerController;


/**
 * @brief The URL for the video playing in the background
 */
@property (nonatomic, strong) NSURL *videoURL;


/**
 * @brief The padding between the bottom of the screen and the bottom of the page control.
 */
@property (nonatomic) CGFloat underPageControlPadding;


@property (nonatomic, strong) OnboardingContentViewController *currentPage;
@property (nonatomic, strong) OnboardingContentViewController *upcomingPage;

/**
 * @brief Switches out buttons if it is the last page
 */
- (void)updateButtons:(BOOL)isLastPage;

/**
 * @brief Convenience class initializer for onboarding with a backround image.
 * @return An instance of OnboardingViewController with the provided background image and content view controllers.
 */
+ (instancetype)onboardWithBackgroundImage:(UIImage *)backgroundImage contents:(NSArray *)contents;


/**
 * @brief Initializer for onboarding with a backround video.
 * @return An instance of OnboardingViewController with the provided background video and content view controllers.
 */
- (instancetype)initWithBackgroundImage:(UIImage *)backgroundImage contents:(NSArray *)contents;


/**
 * @brief Convenience class initializer for onboarding with a backround video.
 * @return An instance of OnboardingViewController with the provided background video and content view controllers.
 */
+ (instancetype)onboardWithBackgroundVideoURL:(NSURL *)backgroundVideoURL contents:(NSArray *)contents;


/**
 * @brief Initializer for onboarding with a backround video.
 * @return An instance of OnboardingViewController with the provided background video and content view controllers.
 */
- (instancetype)initWithBackgroundVideoURL:(NSURL *)backgroundVideoURL contents:(NSArray *)contents;


/**
 * @brief Initializer for onboarding with a backround image and custom buttons.
 * @return An instance of OnboardingViewController with the provided background video, custom buttons and content view controllers.
 */

- (instancetype)initWithBackgroundImage:(UIImage *)backgroundImage
                             leftButton:(UIButton *)leftButton
                            rightButton:(UIButton *)rightButton
                     lastPageLeftButton:(UIButton *)lastPageLeftButton
                    lastPageRightButton:(UIButton *)lastPageRightButton
                               contents:(NSArray *)contents;

/**
 * @brief Initializer for onboarding with a backround video and custom buttons.
 * @return An instance of OnboardingViewController with the provided background video, custom buttons and content view controllers.
 */

- (instancetype)initWithBackgroundVideoURL:(NSURL *)backgroundVideoURL
                                skipButton:(UIButton *)leftButton
                                nextButton:(UIButton *)rightButton
                                doneButton:(UIButton *)lastPageRightButton
                                  contents:(NSArray *)contents;

/**
 * @brief Method to tell the onboarding view controller to automatically move to the next page.
 */
- (void)moveNextPage;

@end
