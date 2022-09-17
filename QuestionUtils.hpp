#pragma once
#include "QuestionManager.hpp"
#include "DEFINITIONS.hpp"

#define SIZE_OF_QA_ARRAY ((std::string::size_type)(sizeof(qa_array) / sizeof(qa_array[0])))

namespace Quizma
{
	class QuestionUtils {

	private:
		std::ifstream question_file;
		std::string line;
		char delimiter = ':';
		std::string qa_array[6];
		std::string *qa_pointer = qa_array;
		std::vector<QuestionManager> qa_vector;

	public:
		QuestionUtils() {}
		std::vector<QuestionManager> loadQuestion();
	};

}