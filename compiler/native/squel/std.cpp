/*
 * This file is part of NectarJS
 * Copyright (c) 2017 - 2020 Adrien THIERRY
 * http://nectarjs.com - https://seraum.com/
 *
 * sources : https://github.com/nectarjs/nectarjs
 * 
 * NectarJS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * NectarJS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with NectarJS.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
 
 #define __NJS_ENV_STD
 #include "njs.h"

 var __NJS_ENV = "std";
 var __NJS_PLATFORM = "{{__PLATFORM__}}";
 
 {INCLUDE}
 
 {DECL}

int main(int argc, char* argv[])
{
	var __NJS_ARGS = __NJS_Create_Array();
	
	for( int i = 0; i < argc; i++)
	{
		__NJS_ARGS[i] = argv[i];
	}

	try 
	{

		{INIT}
		
		#ifdef __NJS_INIT_RAND_SEED
		srand (time(NULL));
		#endif
		{
			{CODE}

			NJS::Event::Loop();
		}
		
	}
	catch(NJS::VAR __NJS_Global_Exception)
	{
		__NJS_Log_Console(__NJS_Global_Exception);
		exit(1);
	}
	return 0;
}
