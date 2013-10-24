//
//  MADContainerParameters.h
//  Part of MADNET iOS SDK -> http://madnet.ru
//
//  Created by Andrey Ivanov.
//  Copyright 2013 TinkoffDigital. All rights reserved.
//  Copyright 2013 MADNET. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 Класс, инкапсулирующий параметры контейнера
 */
@interface MADContainerParameters : NSObject
{
	NSString *m_format;
	NSString *m_p;
	NSInteger m_w;
	NSInteger m_h;
    NSString *m_pid;
}

/** Формат */
@property (nonatomic, copy) NSString *format;
/** SpaceId */
@property (nonatomic, copy) NSString *p;
/** Ширина */
@property (nonatomic) NSInteger w;
/** Высота */
@property (nonatomic) NSInteger h;


@end


/**
 Класс, инкапсулирующий основные параметры таргетирования
 */
@interface MADBaseRequestParametrs : NSObject

@property (nonatomic) NSInteger num;
@property (nonatomic) BOOL testmode;

@end
