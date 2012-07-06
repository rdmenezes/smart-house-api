#pragma once
enum Destination {Server, MessageManager,UserInterface};
enum Action {Start, Stop, Ololo};
enum eServerState {Started, Stopped};

#define	RegisterRequest		0
#define	RegisterResponce	1
#define	LoginRequest		2
#define	LoginResponce		3
#define	LogoutRequest		4
#define	LogoutResponce		5
#define	SendIMRequest		6
#define	SendIMResponce		7
#define	ContactListRequest	8
#define	StatusChangedNotify	9