command=""
isActive=true
underline=$(tput smul)
nounderline=$(tput rmul)
bold=$(tput bold)
normal=$(tput sgr0)
green=$(tput setaf 2)
blue=$(tput setaf 4)
yellow=$(tput setaf 3)
red=$(tput setaf 1)

Main(){
	StartSession
}

StartSession(){
	PrintBanner
	PrintOpeningLine
	while $isActive
	do
		AwaitCommand
	done
}

PrintBanner() {
  echo
  echo "		${green}██████  ██ ██    ██ ██    ██  █████  ███    ███"
  echo "		██   ██ ██ ██    ██  ██  ██  ██   ██ ████  ████"
  echo "		██   ██ ██ ██    ██   ████   ███████ ██ ████ ██"
  echo "		██   ██ ██  ██  ██     ██    ██   ██ ██  ██  ██"
  echo "		██████  ██   ████      ██    ██   ██ ██      ██${normal}"
  echo
}

PrintOpeningLine(){
	echo " ${blue}For the list of commands, type 'help'${normal}"
}

AwaitCommand(){
	read -p ">>> " command
	ExecuteCommand
}

ExecuteCommand(){
	case $command in
		"")
		ExecuteEmptyCommand
		;;
		"help")
		helpCommandExecuting
		;;
		"exit" | "quit")
		ExitTerminal
		;;
		"whois")
		ExecutewhoisCommand
		;;
		"whoami")
		ExecutewhoamiCommand
		;;
		"social")
		ExecutesocialCommand
		;;
		"projects")
		ExecuteprojectsCommand
		;;
		"clear")
		ExecuteclearCommand
		;;
		"date")
		ExecutedateCommand
		;;
		"time")
		ExecutetimeCommand
		;;
		"sysinfo")
		ExecutesysinfoCommand
		;;
		*)
		CommandNotFound
		;;
	esac
}

helpCommandExecuting(){
	echo "		${bold}${yellow}Available commands${normal}"
	echo " -> ${blue}whois${normal}			Who is Shadow?"
	echo " -> ${blue}whoami${normal}			Who is Divyam Sirswal?"
	echo " -> ${blue}social${normal}			Display social networks"
	echo " -> ${blue}projects${normal} 			View coding projects"
	echo " -> ${blue}date${normal} 			Display current date"
	echo " -> ${blue}time${normal} 			Display current time"
	echo " -> ${blue}sysinfo${normal} 			Display system information"
	echo " -> ${blue}help${normal} 			Display this help message"
	echo " -> ${blue}clear${normal} 			Clear the terminal"
	echo " -> ${blue}exit${normal}			Exit the terminal"
}

ExitTerminal(){
	echo " ${red}Seee you soon!!! Bye byee${normal}"
	isActive=false
}

ExecutewhoisCommand(){
	echo " ${yellow}Hey! I am Shadow (A Game Character's dog) and Divyam's favourite one also :)${normal}"
}

ExecutewhoamiCommand(){
	echo " ${yellow}Knock Knock! Who are you? This paradox! We never know who are you, but, we constantly keep finding ourselves${normal}"
}

ExecuteclearCommand(){
	clear
}

ExecutesocialCommand(){
	echo "	${yellow}Linkedin${normal}		${underline}linkedin.com/in/divyamsirswal${nounderline}"
	echo "	${yellow}Instagram${normal}		${underline}instagram.com/divyam_sirswal${nounderline}"
}

ExecuteprojectsCommand(){
	echo "--------------------------------------------------------------------------------------"
	echo "${red}Flowtool${normal}			| ${underline}https://github.com/Divyamsirswal/miniproject-flowtools${nounderline}"
	echo "${red}Snake-game${normal}			| ${underline}https://github.com/Divyamsirswal/snakeGame${nounderline}"
	echo "${red}Tic-tac-toe${normal}			| ${underline}https://github.com/Divyamsirswal/Tic-Tac-Toe---Divyam-Sirswal${nounderline}"
	echo "${red}Dad-joke-generator${normal}		| ${underline}https://github.com/Divyamsirswal/Dad---Jokes---Generator${nounderline}"
	echo "${red}New-year-eve${normal}			| ${underline}https://github.com/Divyamsirswal/New-Year-Eve${nounderline}"
	echo "--------------------------------------------------------------------------------------"
}

ExecutedateCommand(){
	echo " ${green}Today's date is: $(date +"%Y-%m-%d")${normal}"
}

ExecutetimeCommand(){
	echo " ${green}Current time is: $(date +"%T")${normal}"
}

ExecutesysinfoCommand(){
	echo " ${green}System Information:${normal}"
	echo " ${bold}Kernel:${normal} $(uname -r)"
	echo " ${bold}OS:${normal} $(uname -o)"
	echo " ${bold}Hostname:${normal} $(hostname)"
}

ExecuteEmptyCommand(){
	echo " ${red}Please enter a command. For the list of commands, type 'help'${normal}"
}

CommandNotFound(){
	echo " ${red}Command '$command' not found. For the list of commands, type 'help'${normal}"
}

Main
