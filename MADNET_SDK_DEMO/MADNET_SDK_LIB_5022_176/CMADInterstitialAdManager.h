//
//  CMADInterstitialAdManager.h
//  MADNET_SDK
//
//  Created by AndreyIvanov on 13.05.14.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "IMADFulscreenViewControllerDelegate.h"
#import "IMADBaseProtocol.h"

@interface CMADInterstitialAdManager : NSObject<IMADBaseProtocol>

/**
 Конструктор инициализации.
 @param aSpaceId - spaceId контейнера.
 */
- (id) initWithSpaceId: (NSString *) aSpaceId;

/**
 Метод необходимо вызвать ПЕРЕД удалением контейнера
 */
- (void) invalidate;

/**
 Делегат fullscreen-контейнера
 */
@property (nonatomic, assign) NSObject<IMADFulscreenViewControllerDelegate> *delegate;

/**
 Свойство, определяющее поддержку смены ориентации контейнера
 */
@property (nonatomic, assign) BOOL supportRotation;

/**
 SpaceId
 */
@property (nonatomic, copy) NSString *spaceId;
@property (nonatomic, assign) BOOL allowLocation;

- (void) presentFullscreenAdFromRootViewController: (UIViewController *) aViewController;

@end
