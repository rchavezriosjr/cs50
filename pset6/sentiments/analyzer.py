import nltk
from nltk.tokenize import TweetTokenizer

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives="positive-words.txt", negatives="negative-words.txt"):
        """Initialize Analyzer."""
        self.positives = set()
        self.negatives = set()
        
        file = open(positives, "r")
        for line in file:
            self.positives.add(line.rstrip("\n"))
        file.close()
        
        file = open(negatives, "r")
        for line in file:
            self.negatives.add(line.rstrip("\n"))
        file.close()
        
    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        
        tknzr = TweetTokenizer()
        tokenized = tknzr.tokenize(text)
        count = 0
        
        for word in tokenized:
            if word in self.positives:
                count += 1
            elif word in self.negatives:
                count -= 1
            else:
                count += 0
        return count
                
        
        
