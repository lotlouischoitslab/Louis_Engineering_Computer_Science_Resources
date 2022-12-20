# mp3.py
# ---------------
# Licensing Information:  You are free to use or extend this projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to the University of Illinois at Urbana-Champaign
#
# Created by Justin Lizama (jlizama2@illinois.edu) on 09/28/2018
# Modified by Kiran Ramnath (kiranr2@illinois.edu) on 02/13/2021
# Modified by Mohit Goyal (mohit@illinois.edu) on 01/16/2022

import sys
import argparse
import numpy as np

import reader
import tf_idf as tf_idf

"""
This file contains the main application that is run for the Extra Credit Part of this MP.
"""


def main(args):
    train_set, train_labels, dev_set, dev_labels = reader.load_dataset(args.training_dir,args.development_dir,stemming=False,lower_case=True)
    best_tf_idf_words = tf_idf.compute_tf_idf(train_set, train_labels, dev_set)
    
    print("Finished executing compute_tf_idf()")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='ECE 448 MP1 Naive Bayes (Extra Credit)')

    parser.add_argument('--training', dest='training_dir', type=str, default = '../data/spam_data/train',
                        help='the directory of the training data')
    parser.add_argument('--development', dest='development_dir', type=str, default = '../data/spam_data/dev',
                        help='the directory of the development data')
    args = parser.parse_args()
    main(args)
