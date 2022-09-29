import gym 
import os
from stable_baselines3 import PPO
from stable_baselines3.common.vec_env import DummyVecEnv
from stable_baselines3.common.evaluation import evaluate_policy
from stable_baselines3.common.callbacks import EvalCallback, StopTrainingOnRewardThreshold
from stable_baselines3 import DQN

if __name__ == "__main__":
    environment_name = "CartPole-v0" #mapping to the OpenAI environment

    ############################################ JUST FOR CHECKING ########################################################
    # env = gym.make(environment_name)
    # episodes = 5
    # for episode in range(1, episodes+1):
    #     state = env.reset()
    #     done = False
    #     score = 0 
        
    #     while not done:
    #         env.render()
    #         action = env.action_space.sample()
    #         n_state, reward, done, info = env.step(action)
    #         score+=reward
    #     print('Episode:{} Score:{}'.format(episode, score))
    # env.close()
    # 0-push cart to left, 1-push cart to the right
    # print(env.action_space.sample())
    # print(env.action_space)
    # print(env.observation_space.sample())
    ### [More information about the environment](https://github.com/openai/gym/blob/master/gym/envs/classic_control/cartpole.py)
    #############################################################################################################################

    #3. Training RL Algorithms
    env = gym.make(environment_name)
    env = DummyVecEnv([lambda: env])
    model = PPO('MlpPolicy', env, verbose = 1)

    model.learn(total_timesteps=20000)

    #4. Save and Reload Model
    PPO_Path = os.path.join('Training','Saved Models','PPO_MOdel_Cartpole')
    model.save(PPO_Path)

    #5. Evaluation
    evaluate_policy(model, env, n_eval_episodes=10, render=True)

    #6. Test Model
    obs = env.reset()
    while True:
        action, _states = model.predict(obs)
        obs, rewards, done, info = env.step(action)
        env.render()
        if done: 
            print('info', info)
            break
    env.close()


    #8. Adding a callback to the Training Stage
    save_path = os.path.join('Training', 'Saved Models')
    log_path = os.path.join('Training', 'Logs')
    training_log_path = os.path.join(log_path, 'PPO_3')

    env = gym.make(environment_name)
    env = DummyVecEnv([lambda: env])
    stop_callback = StopTrainingOnRewardThreshold(reward_threshold=190, verbose=1)
    eval_callback = EvalCallback(env, 
                                callback_on_new_best=stop_callback, 
                                eval_freq=10000, 
                                best_model_save_path=save_path, 
                                verbose=1)
    
    model = PPO('MlpPolicy', env, verbose = 1, tensorboard_log=log_path)
    model.learn(total_timesteps=20000, callback=eval_callback)
    model_path = os.path.join('Training', 'Saved Models', 'best_model')
    model = PPO.load(model_path, env=env)
    evaluate_policy(model, env, n_eval_episodes=10, render=True)
    env.close()

    #9. Alternate Algorithm
    model = DQN('MlpPolicy', env, verbose = 1, tensorboard_log=log_path)
    model.learn(total_timesteps=20000, callback=eval_callback)
    dqn_path = os.path.join('Training', 'Saved Models', 'DQN_model')
    model.save(dqn_path)
    model = DQN.load(dqn_path, env=env)
    evaluate_policy(model, env, n_eval_episodes=10, render=True)
    env.close()