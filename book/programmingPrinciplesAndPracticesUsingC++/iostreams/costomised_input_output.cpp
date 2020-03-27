/*
 *
 * cout << dec<<1234 <<hex<<1234<<oct<<1234<<endl;
 *
 *
 * dec , hex, oct are manupulators 
 *
 *
 *  cout<<showbase   will show bases for oct(0) and hex(0x)
    noshowbase will not show bases

 *
 * by default cin reads decimal numbers but i can tell it to read hex,oct numbers also
 *
 * cin >>a >>hex>>b>>oct>>d;   // a is decimal,b is hexadecimal,d is octal
 * 
 *
 * if different number formats are prefixed by i.e 0 , 0x  then for taking input we have to unsetf all flags
 *
 * cin.unsetf(ios::dec)
 * cin.unsetf(ios::hex)
 * cin.unsetf(ios::oct)
 * then cin>>a>>b>>c>>d
 

 */ 



                                FLOATING POINT OUTPUT FORMATTING



        manupulators      fixed,scientific , setprecision(val) // precision means total number of digits
                         setw(val)  // set width
                        







                        FILE MANUPULATION


        ios_base::app           to append
        ios_base::ate           open and seek immidiately at the end for various perpose
        ios_base::binary        binary mode
        ios_base::in            reading
        ios_base::out           writing
        ios_base::trunc         truncate file to 0 len



        ofstream ofs(file_name_c_type , ios_base::app)           // for appending
        fstream fs(file_name_c_type , ios_base::in | ios_base::out)         // both for reading and writing


        reading  in writing in BINARY MODE we need to provide the correct address to the read and write function
        we can not use <<  and >> operators for binary mode io
        we need to use read and write functions
                int i; 
                ifs.read(as_bytes(i),sizeof(int));
                ofs.write(as_bytes(i),sizeof(int));
            as you can see we need to provide the starting address of byte which is done by as_byte function;

            template<typename T>
            char* as_byte(T& i){
               void* addr = &i;
               return static_cast<char*>(addr);
            }


            POSITIONING IN FILE

        seekg(int val);  // move reading position to val i.e (val + 1)th character
        peekg(int val);  // move writinging position to val i.e (val + 1)th character


        fstream fs(file_name )          // open for both input and output
