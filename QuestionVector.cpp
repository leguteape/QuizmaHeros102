#include "QuestionVector.hpp"

namespace Quizma
{
	QuestionVector::QuestionVector()
	{
		rng.seed(this->seed);
		question_answer_vector = q1.loadQuestion();
		std::shuffle(question_answer_vector.begin(), question_answer_vector.end(), rng);
	}

	void QuestionVector::displayQuestions()
	{
		for (decltype(question_answer_vector.size()) i = 0; i < question_answer_vector.size(); i++) {
			std::cout << question_answer_vector.at(i) << std::endl;
		}
	}

	void QuestionVector::shuffleQuestions()
	{
		std::shuffle(question_answer_vector.begin(), question_answer_vector.end(), rng);
	}

	std::vector<QuestionManager> QuestionVector::passQuestion()
	{
		return question_answer_vector;
	}
}