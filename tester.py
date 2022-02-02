import random
import os

command_ps = "/home/darian/42/retry_push_swap/push_swap "
command_checker = " |/home/darian/42/retry_push_swap/checker_linux "
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

set = random.sample(range(1, 20), 10)
set_str = " ".join(str(x) for x in set);
result = command_ps + set_str + command_checker + set_str;
stream = os.popen(result)
output = stream.read()
print(output)
range_bot = -10
range_top = 10
for i in range(1, 500):
	for j in range (1, 5):
		set = random.sample(range(range_bot, range_top), i)
		set_str = " ".join(str(x) for x in set);
		result = command_ps + set_str + command_checker + set_str;
		stream = os.popen(result)
		output = stream.read()
		if (output == 'KO\n'):
			print(output, end='')
			print("=> set = ", set_str);
			exit()
	print(bcolors.OKGREEN + "SIZE ", i, " OK")
	range_bot -= 1
	range_top += 1
		