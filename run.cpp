#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool is_int(const char* str){
    for (int i = 0; str[i] != '\0'; ++i)    // basic function, don't use anywhere else, without null termination in strings
    {
        if( str[i] < '0' || str[i] > '9' )  return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    if(argc < 2)    return EXIT_FAILURE;

    string command;
    command.reserve(25);
    command.insert(0, "g++ ");

    /**
     * @param for input -> 
     * `run filename.cpp   <g++_flags>   <version_17>`
    */

    int i;
    bool cmd_arg_to_compiled_program{ false };
    for (i = 1; i < argc-1; ++i)
    {
        if( strcmp(argv[i], "--") == 0 ){
            cmd_arg_to_compiled_program = true;
            break;
        }

        if( is_int(argv[i]) ) continue;   // ignore THOSE integer value `passed to g++` (those passed after '--' to the compiled program are okay)
        command.insert( command.size(), argv[i]);
        command.push_back(' ');
    }

    int version_index = cmd_arg_to_compiled_program ? i-1 : argc-1;
    if( is_int(argv[ version_index ]) )
    {
        command.insert( command.size(), "-std=c++" );
        command.insert( command.size(), argv[ version_index ] );
        command.push_back(' ');
    }else{
        if( ! cmd_arg_to_compiled_program ){    // if there was NO argument to the compiled program
            command.insert( command.size(), argv[argc-1]);
            command.push_back(' ');
        }

        command.insert( command.size(), "-std=c++17" );
        command.push_back(' ');
    }

    if( command.find("-o") == string::npos ){
        command.insert( command.size(), " -o " );
        string fname{argv[1]};

        fname.erase(fname.find('.') == string::npos ? fname.end() : std::find(fname.begin(), fname.end(), '.') , fname.end());   // the extension removed
        command.insert( command.size(), fname.data() );    // the program name
        command.insert( command.size(), " && ./");
        command.insert( command.size(), fname.data() );
        command.push_back(' ');
    }

    // now inserting parameters to pass
    i+=1;   // skip the "--"
    for ( ; cmd_arg_to_compiled_program && i < argc; ++i)
    {
        if( strcmp(argv[i], "--") == 0 ){
            break;
        }
        command.insert( command.size(), argv[i]);
        command.push_back(' ');
    }

    printf(command.data());
    printf("\n\n");
    system(command.data());

    return 0;
}
