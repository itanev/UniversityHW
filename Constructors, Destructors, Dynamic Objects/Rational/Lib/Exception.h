class InvalidDenom
{
    public:
        virtual const char* msg() const throw()
        {
            return "Invalid denomerator! Can't divide by zero.";
        }
} invalid_denom;
