class AnonymousSurvey:
    """Surveyz is anonymous"""
    def __init__(self, question):
        """Store da question, responds to responses."""
        self.question = question
        self.responses = []

    def show_question(self):
        """Show da question"""
        print(self.question)

    def store_response(self, new_response):
        """Store da response"""
        self.responses.append(new_response)

    def show_results(self):
        """Show all responses"""
        print("Survey results:")
        for response in self.responses:
            print(f"- {response}")