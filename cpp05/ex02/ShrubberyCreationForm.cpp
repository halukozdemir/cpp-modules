#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs || ofs.fail() || ofs.bad() || !ofs.is_open())
        throw std::runtime_error("Failed to open file!");

    ofs << "                                                        ," << std::endl;
    ofs << "                                            .__ ._       \\_." << std::endl;
    ofs << "                                     _, _.  '  \\/   \\.-  /" << std::endl;
    ofs << "                                      \\/     .-_`   // |/     \\," << std::endl;
    ofs << "                     .-\"\"\"\"-.          \\.   '   \\`. ||  \\.-'  /" << std::endl;
    ofs << "                    F        Y        .-.`-(   _/\\ V/ \\\\//,-' >-'   ._," << std::endl;
    ofs << "                   F          Y   .__/   `. \\.   ' J   ) ./  / __._/" << std::endl;
    ofs << "                  J         \\, I    '   _/ \\  \\  | |  / /  .'-'.-' `._," << std::endl;
    ofs << "           (       L   \\_.--.| \\_.      ' .___ `\\: | / .--'.-'\"     \\" << std::endl;
    ofs << "         \\ '\\    .  L   /    \\\\/        ._/`-.`  \\ .'.' .'---./__   '" << std::endl;
    ofs << "    \\__  '\\ ) \\._/   `-.__. ` \\\\_. '   .---.  \\     /  /  ,   `  `" << std::endl;
    ofs << "  --'  \\\\  ): // \\,            `-.`__.'     `- \\  /   / _/-.---.__.- ." << std::endl;
    ofs << "     _.-`.'/ /'\\_, ._     >--.-\"\"'____.--\"`_     '   /.'..' \\   \\   _/`" << std::endl;
    ofs << " _ .---._\\ \\'/ '__./__.-..  / .-|(    x_.-'___  |   :' /    _..---_' \\" << std::endl;
    ofs << " .:' /`\\ `. `..'.--'\\      /.' /`-`._  `-,'   ` '   I '_.--'__--..___.--._.-" << std::endl;
    ofs << "     `  `. `\\/'/  _.   _.-'      _.____./ .-.--\"\"-. .-\"    ' _..-.---'   \\" << std::endl;
    ofs << "  -._ .--.\\ / /-./     /   .---'-//.___. .-'       \\__ .--.  `    `.     '`-" << std::endl;
    ofs << " ,--'/.-. ^.   .-.--.  ` _/    _//     ./   _..   .'  `.    \\ \\    |_." << std::endl;
    ofs << "    /' | >.   ' | \\._.-       '    _..'  `.' . `.       )    | |\\  `" << std::endl;
    ofs << "  ./ \\ \\'  ) c| /  \\     \\_..  .--'    ,\\ \\_/`  :    )  (`-. `.|`\\\\" << std::endl;
    ofs << "   \\'  / ,-.  | ` ./`  ._/ `\\\\'.--.,-((  `.`.__ |   _/   \\    |)  `--._/`" << std::endl;
    ofs << "______'\\   |  < __________  //'  //  _)   )/-._`.  (,-')  )  / \\._    /\\. _____" << std::endl;
    ofs << "a:f        |  |        .__./    //  '\\  |//    `.\\ '\\ (  (  <`   ._  '" << std::endl;
    ofs << "           >  |      _.  /   ..-\\ _    _/ \\._  \\ `\\    \\_ `---.-'__" << std::endl;
    ofs << "        . /  `-   _.'        /   `   _/|       J  /`     `-,,-----.`-." << std::endl;
    ofs << "            '  .:'          '`      '          < `   f  I //        `\\_," << std::endl;
    ofs << "              '                         \\.     J        I/\\._        ./" << std::endl;
    ofs << "         __/                            `:     I  .:    K  `          `" << std::endl;
    ofs << "         \\/ )                            `,   J         L" << std::endl;
    ofs << "          )_(_                             .  F  .-'    J" << std::endl;
    ofs << "         /    `.                           .  I  (.   . I _.-.._" << std::endl;
    ofs << "   '    <'    \\ )                     _.---.J/      :'   L -'" << std::endl;
    ofs << " .:.     \\. _.->/                        _.-'_.)     ` `-.`---.,_." << std::endl;
    ofs << ":<        (    \\                    .--\"\"   .F' J) `.`L.__`-.___" << std::endl;
    ofs << ".:        |-'\\_.|                          Y ..Z     ))   `--'  `-" << std::endl;
    ofs << ".         ) | > :                            . '    :'" << std::endl;
    ofs << "          / ) L_J                            .x,." << std::endl;
    ofs << "          L_J .,                             .:<.," << std::endl;
    ofs << "        .'`   `                               :J.,`" << std::endl;
    ofs << "                                           . ;.+K,:." << std::endl;
    ofs << "                                               .,L+.," << std::endl;
}
