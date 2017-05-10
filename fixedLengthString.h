#ifndef FIXEDLENGTHSTRING_H
#define FIXEDLENGTHSTRING_H

template <int length>
class FixedLengthString
	{
    public:
	    FixedLengthString()
			{
		     A[0] = '\0';
	        }
	    FixedLengthString(const char * val)
			{
		     if(strlen(val) == length)
			 strcpy(A, val);
		     else
			 A[0] = '\0';
	        }
	char * getValue()
		{
		return A;
		}

	void setValue(const char * val)
		{
		strcpy(A, val);
		}

	void setValue(const char * val, int n)
		{
		memcpy(A, val, n);
		}

    private:
	    char A[length];
	};

#endif
