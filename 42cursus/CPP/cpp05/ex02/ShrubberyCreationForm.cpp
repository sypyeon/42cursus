#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "unknown", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) { *this = other; }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return *this;
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream fout;

	try
	{
		AForm::execute(executor);

		fout.open((this->getTarget() + "_shrubbery").c_str());
		if (fout.is_open())
		{
			fout << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
			fout << "            {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
			fout << "           {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
			fout << "        {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
			fout << "       {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
			fout << "      _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
			fout << "     {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
			fout << "     _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
			fout << "    {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
			fout << "     {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
			fout << "      {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
			fout << "     {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
			fout << "      {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
			fout << "        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
			fout << "         (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
			fout << "           {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
			fout << "            {/{\\{\\{\\/}/}{\\{\\}/\\}" << std::endl;
			fout << "             {){/ {\\/}{\\/} \\}\\}" << std::endl;
			fout << "                  \\.-'.-/" << std::endl;
			fout << "         __...--- |'-.-'| --...__" << std::endl;
			fout << "  _...--\"   .-'   |'-.-'|  ' -.  ""--..__" << std::endl;
			fout << "-\"    ' .  . '    |.'-._| '  . .  '   sipyeon" << std::endl;
			fout << ".  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
			fout << "         ' ..     |'-_.-|        . ..  , " << std::endl;
			fout << " .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
			fout << "             .'   |'- .-|   '." << std::endl;
			fout << " ..-'   ' .  '.   `-._.-´   .'  '  - ." << std::endl;
			fout << "  .-' '        '-._______.-'     '  ." << std::endl;
       		fout << ".      ~,        ,  ' , .    ,.   .   ." << std::endl;
		}
		fout.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return true;
}

std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
	os << form.getName();
	return os;
}
