import os, math, subprocess, random, sys

class color:
   PURPLE = '\033[95m'
   CYAN = '\033[96;1m'
   DARKCYAN = '\033[36m'
   BLUE = '\033[94;1m'
   GREEN = '\033[92;1m'
   YELLOW = '\033[93;1m'
   RED = '\033[91;1m'
   BOLD = '\033[1m'
   UNDERLINE = '\033[4m'
   END = '\033[0m'

def mean(lst):
    return round(sum(lst) / len(lst))

def calculate(nb, iterations):
	moves = []
	wrong_values = []
	good_values = []
	for x in range(0, iterations):
		nbs = ' '.join([str(random.randint(-2147483648, 2147483647)) for x in range(0, nb)])

		res_cmd = "./push_swap " + nbs + " | ./checker_linux " + nbs	
		res_output = os.popen(res_cmd).read()
		if res_output == "KO\n":
			print(color.BOLD + f"TEST {x + 1} 👉 \t❌ " + color.RED + "KO" + color.END)
			wrong_values.append(("./push_swap " + nbs + " | ./checker_linux " + nbs))
		else:
			print(color.BOLD + f"TEST {x + 1} 👉 \t✅ " + color.GREEN + "OK" + color.END)
			good_values.append(("./push_swap " + nbs + " | ./checker_linux " + nbs))
		
		moves_cmd = "./push_swap " + nbs + " | wc -l"
		moves_output = os.popen(moves_cmd).read()	
		moves.append(int(moves_output))

	if wrong_values:
		f = open('traces_ko.txt', 'a+')
		f.write("** KO ON THESE TESTS **\n\n")
		for item in wrong_values:
			f.write(item + "\n\n")
		f.close()
	else:
		print(color.BOLD + "\nMEAN 👉\t" + str(round(mean(moves))) + " moves" + color.END, end = '')
		print(color.RED + "\nMAX 👉\t" + str(max(moves)) + " moves" + color.END, end = '')
		print(color.GREEN + "\nMIN 👉\t" + str(min(moves)) + " moves" + color.END)
		if good_values:
			f = open('traces_ok.txt', 'a+')
			f.write("** OK ON THESE TESTS **\n\n")
			for item in good_values:
				f.write(item + "\n\n")
			f.close()

if __name__ == "__main__":
	if os.path.exists("traces_ko.txt"):
		os.system("rm -rf traces_ko.txt")

	if os.path.exists("traces_ok.txt"):
		os.system("rm -rf traces_ok.txt")

	if not os.path.exists("push_swap"):
		os.system("make")

	if not os.path.exists("checker_linux"):
		print(color.RED + "\nError: the tester needs checker_linux at the root of the repository!\n" + color.END)
		exit(1)

	print(color.BLUE + f"\n>> Testing 10 times for 100 numbers <<" + color.END)
	calculate(100, 50)

	print(color.BLUE + f"\n>> Testing 10 times for 500 numbers <<" + color.END)
	calculate(500, 50)

	if os.path.exists("traces_ko.txt"):
		print(color.RED + "\n-> You can find details of failed tests in trace_ko.txt file <-" + color.END)
	else:
		print(color.GREEN + "\n-> Congratulations! all the tests are OK! <-" + color.END)
		print(color.RED + "\n-> You can find details of passed tests in trace_ok.txt file <-" + color.END)
