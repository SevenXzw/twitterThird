//
//  ViewController.m
//  twitterThird
//
//  Created by 许振文 on 2021/1/26.
//
#import "GDTwitterThird.h"
#import "ViewController.h"


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    // Do any additional setup after loading the view.
    int channel = 3;
    switch (channel) {
        case 1:{
            NSMutableArray *arr = [NSMutableArray array];
            
            NSData *img01 = UIImageJPEGRepresentation([UIImage imageNamed:@"configuserheadpng"], 0.9);
            NSMutableDictionary *mudic01 = [NSMutableDictionary dictionary];
            [mudic01 setValue:img01 forKey:@"data"];
            [mudic01 setValue:@"byxzw1.jpeg" forKey:@"name"];
            [arr addObject:mudic01];
            
            NSData *img02 = UIImageJPEGRepresentation([UIImage imageNamed:@"inforlogo01"], 0.9);
            NSMutableDictionary *mudic02 = [NSMutableDictionary dictionary];
            [mudic02 setValue:img02 forKey:@"data"];
            [mudic02 setValue:@"byxzw2.jpeg" forKey:@"name"];
            [arr addObject:mudic02];
            
            NSData *img03 = UIImageJPEGRepresentation([UIImage imageNamed:@"head_module01"], 0.9);
            NSMutableDictionary *mudic03 = [NSMutableDictionary dictionary];
            [mudic03 setValue:img03 forKey:@"data"];
            [mudic03 setValue:@"byxzw3.jpeg" forKey:@"name"];
            [arr addObject:mudic03];
            
            
            [GDTwitterThird twitter_share_content:[NSString stringWithFormat:@"测试标准api上传文本byxzw20200319%f",[[NSDate date] timeIntervalSince1970]] andMedias:arr block:^(id  _Nonnull result2, NSError * _Nullable error3) {
                NSLog(@"byxzw2------>%@",result2);
            }];
        }
            break;
        case 2:{
            [GDWhatsAppThird shareWithContent:@"哦 哈 哟～"];
        }
            break;
        case 3:{
            [GDLineThird shareWithContent:@"哦 哈 哟～"];
        }
            break;
            
        default:
            break;
    }
}


@end
