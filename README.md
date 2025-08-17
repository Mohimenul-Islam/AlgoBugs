# AlgoBugs: A Diagnostic Benchmark for LLM Reasoning

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This repository contains the dataset and research paper for the AlgoBugs project, a novel benchmark for evaluating the corner case test generation capabilities of Large Language Models (LLMs) in competitive programming.

## 🎯 About The Project

Current benchmarks for LLMs on coding tasks provide a single success score, failing to reveal why a model fails. AlgoBugs addresses this gap by introducing a diagnostic evaluation. We don't just ask if an LLM can find a bug; we discover what kind of bug it can find.

Our benchmark is built on a high-quality dataset of real-world algorithmic bugs, mined from recent Codeforces contests and classified according to a sophisticated taxonomy.

## 📂 Repository Structure

- **📁 /dataset**: The AlgoBugs benchmark dataset, containing verified bug instances.
- **📁 /Docs**: The draft of the research paper, including the literature review and methodology.
- **(Upcoming) 📁 /scripts**: Scripts for running the benchmark experiments.

## 🚧 STATUS

This is an active Final Year Development Project (FYDP). The dataset is currently under construction.

## 📜 Citing This Work

If you use this dataset, please cite our paper. A BibTeX entry will be provided upon publication.

```bibtex
@inproceedings{islam2025algobugs,
  title={{AlgoBugs: Benchmarking LLMs for Corner Case Test Generation in Competitive Programming}},
  author={Islam, MD. Mohimenul},
  booktitle={To Be Determined},
  year={2025}
}
```
