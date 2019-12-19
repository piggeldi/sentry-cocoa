//
//  SentryOptions.h
//  Sentry
//
//  Created by Daniel Griesser on 12.03.19.
//  Copyright © 2019 Sentry. All rights reserved.
//

#if __has_include(<Sentry/Sentry.h>)
#import <Sentry/SentryDefines.h>
#else
#import "SentryDefines.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class SentryDsn;

NS_SWIFT_NAME(Options)
@interface SentryOptions : NSObject
SENTRY_NO_INIT

/**
 * Init SentryOptions.
 * @param options Options dictionary
 * @return SentryOptions
 */
- (_Nullable instancetype)initWithDict:(NSDictionary<NSString *, id> *)options
                         didFailWithError:(NSError *_Nullable *_Nullable)error;

/**
 * The Dsn passed in the options.
 */
@property(nonatomic, strong) SentryDsn *dsn;

/**
 * This property will be filled before the event is sent.
 */
@property(nonatomic, copy) NSString *_Nullable releaseName;

/**
 * This property will be filled before the event is sent.
 */
@property(nonatomic, copy) NSString *_Nullable dist;

/**
 * The environment used for this event
 */
@property(nonatomic, copy) NSString *_Nullable environment;

/**
 * Is the client enabled?. Default is @YES, if set @NO sending of events will be prevented.
 */
@property(nonatomic, copy) NSNumber *enabled;

@property(nonatomic, assign) NSUInteger maxBreadcrumbs;

/**
 * This block can be used to modify the event before it will be serialized and sent
 */
@property(nonatomic, copy) SentryBeforeSendEventCallback _Nullable beforeSend;

/**
 * Array of integtations to install.
 */
@property(nonatomic, copy) NSArray<NSString *>* _Nullable integrations;

/**
 * Array of default integrations. Will be used if integrations are nil
 */
+ (NSArray<NSString *>*)defaultIntegrations;

/**
 * Defines the sample rate of SentryClient, should be a float between 0.0 and 1.0.
 * valid settings are 0.0 - 1.0 and nil
 */
@property(nonatomic, copy) NSNumber *_Nullable sampleRate;

@end

NS_ASSUME_NONNULL_END