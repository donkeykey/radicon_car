//
//  ViewController.m
//  Cobol
//
//  Created by 川島 大地 on 2014/09/08.
//  Copyright (c) 2014年 川島 大地. All rights reserved.
//

#import "ViewController.h"
#import "BLESerialManager.h"

@interface ViewController ()

@property NSString *button;
@property NSString *direction;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.direction = @"S";
    [[BLESerialManager sharedManager] initBLE];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onTouchConnectBtn:(id)sender {
    [[BLESerialManager sharedManager] connect];
    [[BLESerialManager sharedManager] sendStr:[NSString stringWithFormat:@"~"]];
}
- (IBAction)onTouchDisconnectBtn:(id)sender {
    [[BLESerialManager sharedManager] disconnect];
}

- (IBAction)onTouchA:(id)sender {
    self.direction = @"A";
    [self sendCommand];
}
- (IBAction)onTouchB:(id)sender {
    self.direction = @"B";
    [self sendCommand];
}
- (IBAction)onTouchC:(id)sender {
    self.direction = @"C";
    [self sendCommand];
}
- (IBAction)onTouchD:(id)sender {
    self.direction = @"D";
    [self sendCommand];
}
- (IBAction)onTouchE:(id)sender {
    self.direction = @"E";
    [self sendCommand];
}
- (IBAction)onTouchF:(id)sender {
    self.direction = @"F";
    [self sendCommand];
}
- (IBAction)onTouchG:(id)sender {
    self.direction = @"G";
    [self sendCommand];
}

- (void) sendCommand{
    [[BLESerialManager sharedManager] sendStr:[NSString stringWithFormat:@"%@,%@^",self.direction,@"0"]];
}

@end
