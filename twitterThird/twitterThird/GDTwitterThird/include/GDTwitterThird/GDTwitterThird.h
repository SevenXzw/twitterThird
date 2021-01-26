//
//  GDTwitterThird.h
//  CanleadeosIPad
//
//  Created by 许振文 on 2020/3/10.
//  Copyright © 2020 DuoWen Xu. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

/* twitter application Key/Secret */
static inline NSString * _Nullable consumerKey() { return @"JJiicr5UTlIT0vN3N8WneF7RU";}
static inline NSString * _Nullable consumerSecret() { return @"3GMYH1iCEtcZp82HKB3j4NM7xktIGZb3QsmJ2H7qLq8XSWQe8C";}

NS_ASSUME_NONNULL_BEGIN
@interface twitterAuth : NSObject

/*Oauth1.0*/
///授权流程中的token参数，用于获取pin，校验授权
@property (nonatomic,copy) NSString *oauth_token;
///最终授权校验成功后的token，于后面的twitter业务api都需要的参数
@property (nonatomic,copy) NSString *access_token;
@property (nonatomic,copy) NSString *access_token_secret;
@property (nonatomic,copy) NSString *screen_name;//twitter屏显名字
@property (nonatomic,copy) NSString *userid;

/*Oauth2.0*/
@property (nonatomic,copy) NSString *guest_access_token;
@property (nonatomic,copy) NSString *guest_token;

@end

@interface GDTwitterThird : NSObject

typedef void (^TwitterResetBlock)(void);
typedef void (^TwitterStartCompletion)(id result, NSError *_Nullable error);

@property (nonatomic,copy) TwitterResetBlock resetBlock;
@property (nonatomic,strong) twitterAuth *session;
@property (nonatomic,assign) BOOL         isAuthorization;
+ (GDTwitterThird *)shareInstance;
+ (NSString *)twitterKitURLScheme;
+ (NSString *)twitterAuthURLString;

/**
 
 Use this at "twitterVerification_whenBeUsing" to monitor a twitter's callback and help "twitterVerification_whenBeUsing" to monitor process
 use to combine to
 From those system api:
 - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(id)annotation API_DEPRECATED_WITH_REPLACEMENT("application:openURL:options:", ios(4.2, 9.0)) API_UNAVAILABLE(tvos);
 - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options API_AVAILABLE(ios(9.0)); // no equiv. notification. return NO if the application can't open for some reason
 
 @param application system api
 @param url system api
 @param options system api
 
*/
+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary *)options;


/**
 
 You should set the complition block , when you use Twitter to monitor process.

@param complition A block that defines a monitor . This block returns the void and takes two arguments: the result to result, the error to error
 
*/
+ (void)twitterVerification_whenBeUsing:(TwitterStartCompletion)complition;

/**
 
 twitter_share_content

 @param share_text is required, and the String value whitch to share the text content
 @param mediaArr is optional, and the Array value whitch is uploading medias
 The Array format is
 [
   {
          'data' : media data
          'name' : 'filename'
   }
 , ...
 ]
 @param completion A block that defines a monitor . This block returns the void and takes two arguments: the result to result, the error to error
 
*/
+ (void)twitter_share_content:(NSString *)share_text andMedias:(NSArray <NSDictionary *>*)mediaArr block:(TwitterStartCompletion)completion;

/*

 twitter_friends_list
 
 @param completion A block that defines a monitor . This block returns the void and takes two arguments: the result to result, the error to error
 
 */
+ (void)twitter_friends_list:(TwitterStartCompletion)completion;

/*
 
 deleteUserData
 delete twitter's data
 
 */
+ (void)deleteUserData;

@end

@interface GDWhatsAppThird : NSObject

/**
 *  WhatsApp分享
 *  用於遊戲內分享內容到WhatsApp
 *
 *  @param content   分享彈出界面從父節點 如無可以傳入nil
 *  @return 返回分享动作是否成功
 */
+ (BOOL)shareWithContent:(NSString *_Nonnull)content;

@end

@interface GDLineThird : NSObject

/**
 *  line分享
 *  用於遊戲內分享內容到Line
 *
 *  @param content   分享彈出界面從父節點 如無可以傳入nil
 *  @return 返回分享动作是否成功
 */
+ (BOOL)shareWithContent:(NSString *_Nonnull)content;

@end

NS_ASSUME_NONNULL_END
