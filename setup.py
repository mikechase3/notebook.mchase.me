from setuptools import setup, find_packages

setup(
    name='ci-cd-playground',  # Replace with your package name
    version='0.1.0',           # Replace with the initial version of your package
    author='Mike Chase',        # Replace with your name
    author_email='protectmikechase@gmail.com',  # Replace with your email address
    long_description=open('README.md').read(),  # This reads your Markdown documentation
    long_description_content_type='text/markdown',
    url='https://github.com/mikechase3/notebook.mchase.me',  # URL to your GitHub repo or project
    packages=find_packages(include=['utils', 'utils.*', 'utils/CiCdTest']),  # Include the utils and its subpackages
    classifiers=[
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: MIT License',  # Adjust if you're using a different license
        'Operating System :: OS Independent',
    ],
    # python_requires='>=3.6',  # Minimum Python version required
    install_requires=[
        # 'flake8',  # List any required packages here
        # 'pytest',
        # Add other dependencies as needed
    ],
)
