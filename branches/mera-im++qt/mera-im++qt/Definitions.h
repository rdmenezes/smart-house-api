#pragma once
enum Destination {Server, MessageManager,UserInterface};
enum Action {Start, Stop, Ololo};
enum eServerState {Started, Stopped};
enum NetworkMessageType {
	RegisterRequest,
	RegisterResponce,
	LoginRequest,
	LoginResponce,
	LogoutRequest,
	LogoutResponce,
	SendIMRequest,
	SendIMResponce,
	ContactListRequest,
	StatusChangedNotify
};