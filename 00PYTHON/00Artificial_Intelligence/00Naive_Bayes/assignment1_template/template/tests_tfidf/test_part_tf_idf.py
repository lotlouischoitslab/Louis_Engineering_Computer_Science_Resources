import unittest
from gradescope_utils.autograder_utils.files import check_submitted_files
from gradescope_utils.autograder_utils.decorators import (
    weight,
    visibility,
    partial_credit,
)

import numpy as np

import reader
import tf_idf as tf_idf
import time
import json
from collections import Counter
#keep this as separate file since others look nicer with import at top.
#note, this file checks against autograder paths (/autograder/submission),
#and will fail on local execution.

local_dir = "../"

class TestExtra(unittest.TestCase):

    def setUp(self):
        start_time = time.time()

        stemming = False
        lower_case = True
        self.train_set, self.train_labels, self.dev_set, self.dev_labels = reader.load_dataset(local_dir+"/data/spam_data/train", local_dir+"/data/spam_data/dev", stemming=stemming, lower_case=lower_case)
        train_set, train_labels, dev_set, dev_labels = self.train_set, self.train_labels, self.dev_set, self.dev_labels
        self.tf_idf_words = tf_idf.compute_tf_idf(train_set, train_labels, dev_set)
        print('Test Passed')

    @visibility('visible')
    @partial_credit(10)
    def test_low(self, set_score=None):
        """Evaluating tf-idf correctness"""
        # normal test

        threshold = 0.8

        import pickle
        with open('./tests_tfidf/extra_credit_answer_dev.pkl', 'rb') as f:
            answers = pickle.load(f)
        
        correct = sum([i1 == i2 for i1, i2 in zip(answers, self.tf_idf_words)])
        accuracy = (correct) / len(answers)

        if accuracy > threshold:
            print(f"Accuracy above {threshold}")
            set_score(10)
        elif accuracy > threshold - 0.2:
            print(f"Accuracy below {threshold:.1f} but above {threshold - 0.2:.1f}")
            set_score(5)
        else:
            print(f"Accuracy below {threshold - 0.2:.1f}")
            set_score(2)

