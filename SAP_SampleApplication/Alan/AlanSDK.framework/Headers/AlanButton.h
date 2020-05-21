//
//  AlanButton.h
//  AlanSDK
//
//  Copyright © 2019 Alan AI Inc. All rights reserved.
//  Alan Studio - https://studio.alan.app
//

#import <UIKit/UIKit.h>

@class AlanConfig;

/**
 AlanButton
 This class provides a view with voice button
 
 Usage:
 
 1. Create AlanButton class as usual UIView
 2. Place AlanButton to some place in your application
 3. AlanButton will handle tap actions to start and stop recording
 */
@interface AlanButton: UIView

/**
 Creates new AlanButton instance

 @param config AlanConfig object for configuration
 @return AlanButton object with given parameters
 */
- (instancetype)initWithConfig:(AlanConfig *)config;

/**
 Plays text via Alan

 @param text Text to be played
 */
- (void)playText:(NSString *)text;

/**
 Sends voice synchronized data event

 @param data Command data event to be send
 */
- (void)playData:(NSDictionary *)data __attribute__((deprecated("Use 'playCommand'")));

/**
 Sends voice synchronized data event

 @param command Command data event to be send
 */
- (void)playCommand:(NSDictionary *)command;

/**
 Set visual state of an application
 
 @param data Data with visual state description
 */
- (void)setVisual:(NSDictionary *)data __attribute__((deprecated("Use 'setVisualState'")));

/**
 Set visual state of an application
 
 @param visualStateData Data with visual state description
 */
- (void)setVisualState:(NSDictionary *)visualStateData;

/**
Calls specific Alan studio project api
 
 @param method Method name, like "script::someApiName", or just - "someApiName"
 @param params Method data params
 @param callback Callback to handle result
 */
- (void)call:(NSString *)method withParams:(NSDictionary*)params callback:(void(^)(NSError *error, NSString *object))callback __attribute__((deprecated("Use 'callProjectApi(_:withData:callback:)'")));

/**
Calls specific Alan studio project api

@param method Method name, like "script::someApiName", or just - "someApiName"
@param data Method data params
@param callback Callback to handle result
*/
- (void)callProjectApi:(NSString *)method withData:(NSDictionary*)data callback:(void(^)(NSError *error, NSString *object))callback;

/**
 * Activate Alan voice button
 */
- (void)activate;

/**
 * Deactivate Alan voice button
 */
- (void)deactivate;

/// Indicator that Alan voice button is activated
@property (readonly) BOOL isActivated;

@end
