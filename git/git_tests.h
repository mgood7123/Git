﻿

void gitprefix(test_clone)(void) {
	git("clean init");
	//git("config --global user.email smallville7123@gmail.com");
	//git("config --global user.name mgood7123");
	puts("testing");
	mkdir("tests",0777);
	mkdir("tests/clone",0777);
	chdir("tests/clone");
	git("clone https://github.com/dztall/ccr_resources.git");
	//git("clone https://github.com/dztall/ccr_resources renamed_clone");
	chdir("../../");
	puts("testing done");
	git("clean init");
}

void gitprefix(test_push)(void) {
	git("clean init");
	//git("config --global user.email smallville7123@gmail.com");
	//git("config --global user.name mgood7123");
	puts("testing");
	git("init tests/push");
	chdir("tests/push");
	git("status");
	touch("test");
	git("status");
	mkdir("b",0777);
	git("status");
	touch("b/l");
	git("status");
	git("add -A");
	git("status");
	touch("b/j");
	git("status");
	git("add -A");
	git("status");
	git("commit -a");
	git("status");
	git("remote add origin https://github.com/mgood7123/git_implementation_test_push.git");
	git("remote show -v");
	git("push origin master");
	git("status");
	chdir("../../");
	puts("testing done");
	git("clean init");
}

void gitprefix(test_push2)(void) {
	git("clean init");
	//git("config --global user.email smallville7123@gmail.com");
	//git("config --global user.name mgood7123");
	puts("testing");
	git("init tests/push_twice");
	chdir("tests/push_twice");
	git("status");
	touch("test");
	git("status");
	mkdir("b",0777);
	git("status");
	touch("b/l");
	git("status");
	git("add -A");
	git("status");
	touch("b/j");
	git("status");
	git("add -A");
	git("status");
	git("commit -a");
	git("status");
	git("remote add origin https://github.com/mgood7123/git_implementation_test_push_twice.git");
	git("remote show -v");
	git("push origin master");
	git("status");
	chdir("../../");
	puts("testing done");
	git("clean init");
}

void gitprefix(test_rename_detection)(void) {
	git("clean init");
	puts("testing");
	git("init tests/rename_detection");
	chdir("tests/rename_detection");
	git("status");
	touch("test_no_add");
	touch("test_add");
	touch("test_commit");
	git("status");
	git("add test_commit");
	git("commit -a");
	git("add test_add");
	system("mv test_no_add test_no_add_rename");
	system("mv test_add test_add_rename");
	system("mv test_commit test_commit_rename");
	git("status");
	chdir("../../");
	puts("testing done");
	git("clean init");
}

int gitprefix(test)(int argc, char * argv[]) {
	if (argc < 2) giterrornomessage("%s requires an additional command", argv[0]);
	if(strcmp(argv[1], "clone") == 0) return gitprefix(test_clone)();
	else if(strcmp(argv[1], "push") == 0) return gitprefix(test_push)();
	else if(strcmp(argv[1], "push2") == 0) return gitprefix(test_push2)();
	else if (argc > 1) {
		if (argc < 3) giterrornomessage("%s requires an additional command", argv[1]);
		if(strcmp(argv[1], "rename") == 0 && strcmp(argv[2], "detection") == 0) return gitprefix(test_rename_detection)();
		else giterrornomessage("%s is not a valid sub command of %s", argv[2], argv[1]);
	}
	else giterrornomessage("%s is not a valid sub command of %s", argv[1], argv[0]);
}
