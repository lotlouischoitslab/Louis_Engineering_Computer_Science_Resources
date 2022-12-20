import unittest
from gradescope_utils.autograder_utils.decorators import (
    weight,
    visibility,
    partial_credit,
)
from gradescope_utils.autograder_utils.files import check_submitted_files

import numpy as np
import time
import os
import sys
import reader
import naive_bayes as nb
#from sklearn.metrics import confusion_matrix

# keep this as separate file since others look nicer with import at top.
# note, this file checks against autograder paths (/autograder/submission),
# and will fail on local execution.
# tests unigram cases for hidden, lower case, no stemming
local_dir = "../"


def compute_accuracies(predicted_labels, dev_labels):
    yhats = predicted_labels
    accuracy = np.mean(yhats == dev_labels)
    if (len(yhats) != len(dev_labels)):
        print("predicted and gold label lists have different lengths")
        accuracy = 0
    tp = np.sum([yhats[i] == dev_labels[i] and yhats[i] == 1 for i in range(len(yhats))])
    tn = np.sum([yhats[i] == dev_labels[i] and yhats[i] == 0 for i in range(len(yhats))])
    fp = np.sum([yhats[i] != dev_labels[i] and yhats[i] == 1 for i in range(len(yhats))])
    fn = np.sum([yhats[i] != dev_labels[i] and yhats[i] == 0 for i in range(len(yhats))])
    return accuracy, fp, fn, tp, tn


# rotate a list by a selected number of places
def rotate(inlist,numplaces):
    numplaces=numplaces%len(inlist)
    rv= inlist[numplaces:] + inlist[:numplaces]
    return rv


# rotate labels and docs by the same number of places, so we can avoid
#     people cheating using the fact that the reader doesn't scramble
#     the pos and neg examples.
# Notice that the data is a list but the labels are a numpy array
#     for historical reasons.    And roll works backwards from
#     the obvious way to use slicing, hence the minus sign.
def rotate_dataset(indata,inlabels,numplaces):
    outdata=rotate(indata,numplaces)
    outlabels=np.roll(inlabels,-numplaces,axis=0)
    return outdata,outlabels

# Can their bigram code correctly classify a synthetic dataset?

# Make sure their unigram code passes a synthetic example, including paying attention
#    to pos_prior.   Returns True iff they pass.



class TestPartSearch(unittest.TestCase):
    @visibility("visible")
    @partial_credit(20)
    def test_nb_dev(self, set_score=None):
        """unigram model on dev set with student's parameter settings """

        # synthetic test
        penalty=1.0

        # normal test
        train_set, train_labels, dev_set, dev_labels = nb.load_data(
            local_dir + "/data/spam_data/train",
            local_dir + "/data/spam_data/dev",
            silently=True
        )
        # rotate the testing set so we can be sure they aren't cheating
        dev_set,dev_labels = rotate_dataset(dev_set,dev_labels,57)

        ## test about the counter:
        pos_uni_student,neg_uni_student = nb.create_word_maps_uni(train_set, train_labels,None)
        pos_uni_true = np.load("./counter_data/pos_uni.npy",allow_pickle=1)
        neg_uni_true = np.load("./counter_data/neg_uni.npy",allow_pickle=1)
        if pos_uni_true == pos_uni_student and neg_uni_true == neg_uni_student:
            print("output of create_word_maps_uni is correct!")
        else:
            print("output of create_word_maps_uni is not the same with the solution!")

        pos_bi_student,neg_bi_student = nb.create_word_maps_bi(train_set, train_labels,None)
        pos_bi_true = np.load("./counter_data/pos_bi.npy",allow_pickle=1)
        neg_bi_true = np.load("./counter_data/neg_bi.npy",allow_pickle=1)
        if pos_bi_true == pos_bi_student and neg_bi_true == neg_bi_student:
            print("output of create_word_maps_bi is correct!")
        else:
            print("output of create_word_maps_bi is not the same with the solution!")
            # print("sanity check not passed")


        predicted_labels = nb.naiveBayes(train_set, train_labels, dev_set,silently=True)
        (
            accuracy,
            false_positive,
            false_negative,
            true_positive,
            true_negative,
        ) = compute_accuracies(predicted_labels, dev_labels)
        print("Accuracy: ", accuracy)
        print("Number of False Positive: ", false_positive)
        print("Number of False Negative: ", false_negative)
        print("Number of True Positive: ", true_positive)
        print("Number of True Negative: ", true_negative)
        total_score = 0

        if accuracy >= 0.70:
            total_score += 5
            print("+ 5 points for accuracy  above " + str(0.70))
        else:
            print("Accuracy needs to be above " + str(0.70))
        if accuracy >= 0.75:
            total_score += 5
            print("+ 5 points for accuracy above " + str(0.75))
        else:
            print("Accuracy needs to be above " + str(0.75))
        if accuracy >= 0.80:
            total_score += 5
            print("+ 5 points for accuracy above " + str(0.80))
        else:
            print("Accuracy needs to be above " + str(0.80))
        if accuracy >= 0.85:
            total_score += 5
            print("+ 5 points for accuracy above " + str(0.85))
        else:
                print("Accuracy needs to be above " + str(0.85))

        total_score *= penalty

        set_score(total_score)



    @visibility("visible")
    @partial_credit(20)
    def test_bigram_dev(self, set_score=None):
        """bigram model on dev set with student's parameter settings"""
        # synthetic check
        bigram_check_result = 1.0

        # normal test
        train_set, train_labels, dev_set, dev_labels = nb.load_data(
            local_dir + "/data/spam_data/train",
            local_dir + "/data/spam_data/dev",
            silently=True
        )

        # rotate the testing set so we can be sure they aren't cheating
        dev_set,dev_labels = rotate_dataset(dev_set,dev_labels,57)
        predicted_labels = nb.bigramBayes(train_set, train_labels, dev_set,silently=True)
        (
            accuracy,
            false_positive,
            false_negative,
            true_positive,
            true_negative,
        ) = compute_accuracies(predicted_labels, dev_labels)
        print("Accuracy: ", accuracy)
        print("Number of False Positive: ", false_positive)
        print("Number of False Negative: ", false_negative)
        print("Number of True Positive: ", true_positive)
        print("Number of True Negative: ", true_negative)
        total_score = 0
        if accuracy >= 0.79:
            total_score += 5
            print("+ 1.25 points for accuracy  above " + str(0.79))
        else:
            print("Accuracy needs to be above " + str(0.79))
        if accuracy >= 0.82:
            total_score += 5
            print("+ 1.25 points for accuracy above " + str(0.82))
        else:
            print("Accuracy needs to be above " + str(0.82))
        if accuracy >= 0.85:
            total_score += 5
            print("+ 1.25 points for accuracy above " + str(0.85))
        else:
            print("Accuracy needs to be above " + str(0.85))
        if accuracy >= 0.89:
            total_score += 5
            print("+ 1.25 points for accuracy above " + str(0.89))
        else:
            print("Accuracy needs to be above " + str(0.89))
        
        total_score *= bigram_check_result
        set_score(total_score)


