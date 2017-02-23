#include <string>

#ifndef ERROR_H_
#define ERROR_H_

class Error{
	private:
		std::string message;

	public:
		Error(std::string m){message = m;}
		std::string getMessage(){return message;}
};

#endif /* ERROR_H_ */
