//
//  CMADADSourceBuilder.h
//  MADNET_SDK
//
//  Created by AndreyIvanov on 06.03.14.
//
//

#import <Foundation/Foundation.h>
#import "CmAdBannerEntity.h"

@interface CMADADSourceBuilder : NSObject

+ (NSString *) build: (CmAdBannerEntity *) aADEntity;
- (void) build: (NSURL *) aURL withResponcehandler: (void (^)(NSString *aValidHTMlString)) aHandler;

@end
