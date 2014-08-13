//
//  MADContainerParameters.h
//  MADNET_SDK
//
//  Created by AndreyIvanov on 22.01.14.
//
//

#import <Foundation/Foundation.h>

/**
 Класс, инкапсулирующий параметры контейнера
 */
@interface MADContainerParameters : NSObject

/** Формат */
@property (nonatomic, copy) NSString *format;
/** SpaceId */
@property (nonatomic, copy) NSString *p;
/** Ширина */
@property (nonatomic) NSInteger w;
/** Высота */
@property (nonatomic) NSInteger h;
/** Тестовый режим*/
@property (nonatomic) BOOL testmode;

@end
