struct message {
	string operator<20>;
	string message<255>;
	long timestamp;
};
struct historic {
	message list<>;
	int size;
};
program rpcchat {
	version CHATMESSAGING {
		void writechat(message) = 1;
		historic getChat(long timestamp) = 2;
	} = 1;
} = 0x20000001;
